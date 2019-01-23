#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct littleNO littleNO;

struct littleNO{
	int item;
	littleNO *proximo;
};

littleNO* CriarlittleNODoTeus(){

	return NULL;
}

littleNO* add(littleNO *head, int item){
	littleNO *novono = (void*) malloc(sizeof(littleNO));
	novono->item = item;
	novono->proximo = head;
	return novono; 	

}

int isempty(littleNO *head)
{
	return (head == NULL);
}

littleNO* remover(littleNO *head, int item){
	littleNO *anterior = NULL;
	littleNO *atual = head;
	while(atual != NULL && atual->item != item)
	{
		anterior = 	atual;
		atual = atual->proximo;
	}
	if(atual == NULL)
	{
		return head;
	}
	if(anterior == NULL)
	{
		head = atual->proximo;
	} else{
		anterior->proximo = atual->proximo;
	}
	free(atual);
	return head;
}

littleNO* search_list(littleNO *head, int item){
	while(head != NULL && head->item != item)
	{
		head = head->proximo;
	}
	return head;
}

void printLista(littleNO *head){
	while(head != NULL)
	{
		printf("%d\n", head->item);
		head = head->proximo;
	}
}

int main(){
	int n;
	littleNO *head = CriarlittleNODoTeus();
	head = add(head, 2);
	head = add(head, 27);
	head = add(head, 7);
	printLista(head);
	puts("----");
        head = remover(head,27);
	printLista(head);
        search_list(head, 3) ? puts("\n \\o/ Found it!") : puts("\n;-; I haven't found!");
    

}
