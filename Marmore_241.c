#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int bin_search(int *a, int valor, int inicio, int fim){
	int meio = (inicio+fim) / 2;
	if(inicio>fim)
	{
		return -1;
	}
	else if(a[meio]<valor) { bin_search(a,valor,meio+1, fim); }
	else if(a[meio]>valor) { bin_search(a,valor,inicio, meio-1); }
	else if(a[meio]==valor) 
		{
			while(1)
			{
			    if(valor!=a[meio-1]){break;}
				meio--;
			}
			return meio+1;  
		}
}
void trocar(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
void insert_sort(int *a, int n){
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main() {
	int n_marm = 1, n_consul = 1, i = 1;
	int saida, count = 1;
	///int *marm = (int*) malloc(sizeof(int));
	///int *consul = (int*) malloc(sizeof(int));
	int marm[10000], consul[10000];
	while(1)
	{
	    scanf("%d%d", &n_marm, &n_consul);
	    if(n_marm==0 && n_consul==0) {break;}
		printf("CASE# %d:\n", count);
		for(i = 0; i < n_marm; i++)
		{
		    //marm = (int *) realloc(marm, sizeof(int) * (i+1));
			scanf("%d", &marm[i]);
		}
		for(i = 0; i < n_consul; i++)
		{
		    //consul = (int *) realloc(consul, sizeof(int) * (i+1));
			scanf("%d", &consul[i]);
		}
		insert_sort(marm,n_marm);
		for(i = 0; i < n_consul; i++)
		{
			saida = bin_search(marm,consul[i],0,n_marm-1);
			if(saida==-1)
			{
				printf("%d not found\n", consul[i]);
			}
			else printf("%d found at %d\n", consul[i], saida);
		}
		memset(marm,0,10000);
		memset(consul,0,10000);
		//free(marm);
		//free(consul);
		count++;
	}
	
	return 0;
}
