#include <stdio.h>

struct noArvore
{
	int valor;
	struct noArvore *esquerda; //filhoesquerda
	struct noArvore *direita; //filhodireita
};

typedef struct noArvore nozinho;

//funçao
nozinho *adcionarno(int valor, nozinho *esq, nozinho *dir)
{
	nozinho *n = (nozinho*) malloc(sizeof(nozinho));
	if(n==NULL)
	{
		exit(1);
	}
	else
	{
// 		n->valor = valor;
// 		n->esquerda = esq;
// 		n->direita = dir;
        (*n).valor = valor;
        (*n).direita = dir;
        (*n).esquerda = esq;
	}
	return n;
}
void preprint(nozinho *n)
{
	if(n != NULL)
	{
		printf("%d ", n->valor);
		preprint(n->esquerda);
		preprint(n->direita);
	}

}
void main(){
	nozinho *n = adcionarno(15,adcionarno(10,adcionarno(11,NULL,NULL),NULL),adcionarno(50,adcionarno(20,NULL,NULL),NULL));
	preprint(n);
}
