#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
//Duplamente encadeada, agr al?m de cabe?a, tem bundinha.
typedef struct nozinho nozinho;

struct nozinho{
	int item;
	nozinho *proximo;
	nozinho *anterior;
};

nozinho* CriarnozinhoDoTeus(){

	return NULL;
}

nozinho* add(nozinho *head, int item){
	nozinho *novono = (nozinho*) malloc(sizeof(nozinho));
	novono->item = item;
	novono->proximo = head;
	if(head != NULL)
		head->anterior = novono;
	return novono; 	

}
void printLista(nozinho *head){
	while(head != NULL)
	{
		printf("%d ", head->item);
		head = head->proximo;
	}
}
void SortC(nozinho *head, nozinho *aux){
	if(head->item > aux->item)
	{
		int auxiliar = head->item;
		head->item = aux->item;
		aux->item = auxiliar;
	}
}
void SortD(nozinho *head, nozinho *aux){
	if(head->item < aux->item)
	{
		int auxiliar = head->item;
		head->item = aux->item;
		aux->item = auxiliar;
	}
}
void Sort(nozinho *head, int ordem){
	while(head != NULL)
	{
		nozinho *aux = head;
		while(aux != NULL)
		{
			ordem ? SortC(head, aux) : SortD(head, aux);	
			aux = aux->proximo;
		}
		head = head->proximo;
	}
}
nozinho *invertinho(nozinho *head){
	nozinho *novahead = CriarnozinhoDoTeus();
	while(head != NULL)
	{
		novahead = add(novahead, head->item);
		head = head->proximo;
	}
	free(head);
	return novahead;
}
int main(){
	int n;
	nozinho *head = CriarnozinhoDoTeus(); 
	while(TRUE)
	{
		scanf("%d", &n);
		if(n == -1) {break;}
		head = add(head, n);    
	}
	Sort(head, 1); // Se 0, decrescente, se 1, crescente
	//head = invertinho(head);
    printLista(head);
}