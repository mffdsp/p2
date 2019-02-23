#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 700


int primo = 7;
int  M_lista = -1;
int pertencidos[300];
typedef struct element element;
struct element
	{
		int key;
		int value;
		element *next;
};

typedef struct hash
	{
		int size;
		element *grupo[MAX];
	}hash;

hash *create_hash(){
	hash *hs = (hash*) malloc(sizeof(hash));
	int i;
	hs->size = -1;
	for(i = 0; i < MAX; i++)
	{
		hs->grupo[i] = NULL;
	}
	return hs;
}
float fator_carga(hash *hs){
	return (float) hs->size / primo;
}
element* add_fila(element *head, int item, int *gasto) // inserir no final da lista
{   
    int maiorlista = 0;
    element *novo = (element*) malloc(sizeof(element));
	novo->key = item;
	novo->value = item;
    element *aux = head; 
    while(aux->next != NULL)
        {	
            maiorlista++;
        	*gasto += 1;
            aux = aux->next;
            if(maiorlista > M_lista)
            {
                 M_lista = maiorlista;
            }
            
        }
    aux->next = novo;
    return head;

}
element* add_fila_sem_gasto(element *head, int item) // inserir no final da lista
{
    element *novo = (element*) malloc(sizeof(element));
	novo->key = item;
	novo->value = item;
    element *aux = head; 
    while(aux->next != NULL)
        {	
            aux = aux->next;
        }
    aux->next = novo;
    return head;

}
void readd(hash *hs){
	primo = (2*primo) - 1;
	int i = 0;
	while(i < hs->size)
	{
	    if(hs->grupo[i] != NULL)
	    {
	        int value = hs->grupo[i]->value;
	        element *novo = (element*) malloc(sizeof(element));
        	novo->key = value;
	        novo->value = value;
		    int h = value % primo;
		    if(hs->grupo[h] == NULL)
		    {
			    hs->grupo[h] = novo;

		    } else {
	    	element *save = hs->grupo[h];
	   	 	save = add_fila_sem_gasto(save, value);
	    	hs->grupo[h] = save;
	    	return 0;
		}
	    }
	    i++;
	}

}
int add(hash *hs, int key, int value, int primo, int *gasto){
    int j;
    for(j = 0; j < hs->size; j++)
    {
        if(pertencidos[j] == value)
        {
            return 0;
        }
    }
    pertencidos[hs->size] = value;
	int h = key % primo;
	element *novo = (element*) malloc(sizeof(element));
	novo->key = key;
	novo->value = value;
	if(hs->grupo[h] == NULL)
	{
		hs->grupo[h] = novo;
		return 1;
	}
	else 
	{
	    element *save = hs->grupo[h];
	    save = add_fila(save, value, gasto);
	    hs->grupo[h] = save;
	    return 1;
	}
}

int get(hash *hs, int key, int *gasto){
	int h = key % primo;
	
	while(hs->grupo[h] != NULL)
	{
	    *gasto += 1;
		if(hs->grupo[h]->key == key)
		{
			return 1;
		}
		h = (h + 1)	% MAX;
	}
	return 0;
}
int rmv(hash *hs, int key, int *gasto){
	int h = key % primo;
	while(hs->grupo[h] != NULL)
	{
		*gasto += 1;
		if(hs->grupo[h]->key == key)
		{
			hs->size -= 1;
			hs->grupo[h]->key = -99;
			return 1;
		}
		h = (h + 1)	% MAX;
	} 
	return 0;
}

void printlista(element *lt){
    while(lt != NULL)
    {
        printf("-> %d ", lt->value);
        lt = lt->next;
    }
    
}

int main(){
	int n, op = 0;
	hash *hs = create_hash();
	char cmd[6];
	while(scanf("%s", cmd) != EOF)
	{
		
		scanf("%d", &n);
		getchar();
		int gasto = 0;
		if(fator_carga(hs)>=0.75)
	    {
		    readd(hs);
	    }
		if(!strcmp(cmd, "ADD"))
		{
		    int vdd = add(hs, n, n, primo, &gasto);
		    hs->size += 1;
		    printf("%d %d %d\n", op, vdd, gasto);
		}
		if(!strcmp(cmd, "DEL"))
		{
		    int vdd = rmv(hs, n, &gasto);
			printf("%d %d %d\n", op, vdd, gasto);
		}
		if(!strcmp(cmd, "HAS"))
		{
		    int vdd = get(hs, n, &gasto);
			printf("%d %d %d\n", op, vdd , gasto);
		}
		if(!strcmp(cmd, "PRT"))
		{
			printf("%d %d %d %d\n", op, primo, hs->size,  M_lista);
		}
        
		op += 1;
	}
}
