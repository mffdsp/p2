//Stack
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 300

typedef struct nozinho nozinho;
struct nozinho{
	int item;
	nozinho *proximo;
};


nozinho* CriarnozinhoDoTeus(){

	return NULL;
}
typedef struct stack{
	nozinho *valores[MAX];
	int atual;
}stack;


stack *criarstack(){
	stack *novastack = (stack*) malloc(sizeof(stack));
	novastack->valores[novastack->atual] = NULL;
	novastack->atual = 0;
	return novastack;
}
stack *adds(stack *stackzinha, nozinho *head){
		if(stackzinha->atual == MAX)
		{
			puts("TA CHEIO MEU FILHO");
		}
		else 
		{
			stackzinha->valores[stackzinha->atual] = head;
			stackzinha->atual++;
		}
		return stackzinha;
}

int isempty(stack *stackzinha){
	return stackzinha == NULL;
}

void printLista(nozinho *head){
	while(head != NULL)
	{
		printf("%d ", head->item);
		head = head->proximo;
	}
	
}

stack *pop(stack *stackzinha){
	if(stackzinha->atual == 0)
	{
		puts("EMPTY STACK");
		return stackzinha;
	}
	else 
		printLista(stackzinha->valores[stackzinha->atual]);
		stackzinha = stackzinha->valores[stackzinha->atual--];
	return stackzinha;
} 

nozinho *add(nozinho *head, int item){
	nozinho *novono = (nozinho*) malloc(sizeof(nozinho));
	novono->item = item;
	novono->proximo = head;
	return novono; 	
}

nozinho *invertinho(nozinho *head){
	nozinho *novahead = NULL;
	while(head != NULL)
	{
		novahead = add(novahead, head->item);
		head = head->proximo;
	}
	return novahead;
}

//TIRA O DE CIMA DE PILHA
int main(){
	stack *novastack = criarstack();
	
	char comando[30];
	int n;
	char espa;
	nozinho *head = CriarnozinhoDoTeus();
	while(scanf("%s", comando) != EOF)
	{
		if(!strcmp(comando, "PUSH"))
		{
		    head = CriarnozinhoDoTeus();
		    while(1)
		    {
			scanf("%d", &n);
			head = add(head, n);
			scanf("%c", &espa);
			if(espa == '\n'){break;}
		    }
		    head = invertinho(head);
		    novastack = adds(novastack, head);
		}
		if(!strcmp(comando, "POP"))
		{
		    novastack = pop(novastack);
		  
		}
		
	}
}
