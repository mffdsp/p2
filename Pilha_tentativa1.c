//Stack
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 300;
typedef struct nozinho nozinho;
nozinho* CriarnozinhoDoTeus(){

	return NULL;
}

nozinho *addlista(nozinho *head, char item){
	nozinho *novono = (nozinho*) malloc(sizeof(nozinho));
	novono->item = item;
	novono->proximo = head;
	return novono; 	

}
struct nozinho{
	char item;
	nozinho *proximo;
}

typedef struct stack{
	nozinho *topo;

}stack;

stack *criarstack(){
	stack *novastack = (stack*) malloc(sizeof(stack));
	novastack->topo = NULL;
	return novastack;
}
void addpilha(stack *stackzinha, char item){
	nozinho *novoTopo = (nozinho*) malloc(sizeof(nozinho));
	novotopo->item = item;
	novotopo->proximo = stackzinha->topo;
	stackzinha->topo = novotopo;

}
int isempty(stack *stackzinha){
	return stackiznha == NULL;
}
int pop(stack *stackzinha){
	if(isempty(stackzinha))
	{
		puts("TA VAZIO");
		return -1;
	}
	else return stackzinha->item[stackzinha->atualtam--];

} 
//TIRA O DE CIMA DE PILHA
int main(){
	stack *novastack = criarstack();
	nozinho *head = CriarnozinhoDoTeus();
	char n;
	char comando[10];
	while(1)
	{
		gets(comando);
		if(strcmp(comando, "PUSH") == 0)
		{
			while(scanf("%c", &n) != '\n')
			{
				head = addlista(head, n);
			}
		}
		//addpilha // EU N SEI MDS DO CEU

		
	}


}
