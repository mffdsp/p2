

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}

//43 45 42 47//
//ad, sub, mult, div//
int tamanho = 0;
int IS_EMPTY(STACK *stackzinha){
	return stackzinha->head->next == NULL;
}

STACK* Create_stack(){
	STACK *novastack = (STACK*) malloc(sizeof(STACK));
	novastack->head = NULL;
	return novastack;
}

void PUSH(STACK* stack, int element){
	NODE *top = (NODE*) malloc(sizeof(NODE));
	top->element = element;
	top->next = stack->head;
	stack->head = top;
	tamanho++;

}
int POP(STACK* stack){
	int v = stack->head->element;
	stack->head = stack->head->next;
	return v;

}
void result(STACK* stack, char operation){
	int valor1, valor2, valor3;
	if(operation == '+')
	{
		valor1 = POP(stack);
		valor2 = POP(stack);
		valor3 = valor1 + valor2;

		PUSH(stack, valor3);
	}
	if(operation == '-')
	{
		valor1 = POP(stack);
		valor2 = POP(stack);
		valor3 = valor2 - valor1;
		PUSH(stack, valor3);
	}
	if(operation == '*')
	{
		valor1 = POP(stack);
		valor2 = POP(stack);
		valor3 = valor1 * valor2;
		PUSH(stack, valor3);
	}
	if(operation == '/')
	{
		valor1 = POP(stack);
		valor2 = POP(stack);
		valor3 = valor2/valor1;
		PUSH(stack, valor3);
	}
	return;

}
void Calculadora(STACK* calculadora, int size)
{	
  	int i = 0;
  	int valor;
  	char valorchar;
  	int valorint;
  	int negativo = 0;
  	while(i < size)
    {
    	scanf("%d", &valor);
  		valorchar = (char) valor;
    	if(valorchar != '/' && valorchar != '*' && valorchar != '+' && valorchar != '-')
    	{	
    		printf("VALOR: %d\n", valor);
    		PUSH(calculadora, valor);
    	}
    	else if(tamanho >= 2)
    	{
    		printf("LETRA: %c\n", valorchar);
    		result(calculadora, valor);
    	}
    	i++;
    
    }
}
