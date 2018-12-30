
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>	

using namespace std;

typedef struct noArvore
{
	int valor;
	struct noArvore *esquerda; //filhoesquerda
	struct noArvore *direita; //filhodireita
} nozinho;

typedef struct membro{
	char letra;
	int freq;
} membro;

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


void unir(membro *tabelinha, int qnt){
	if(qnt < 2)
	{
		return;
	}


}

int CharSearch(membro *tabelinha , char busca, int tam){
    int i;
	for(i = 0; i < tam; i++)
	{
	   if(busca == tabelinha[i].letra)
	   {
	       return i;
	   }
	}
	return -1;
	
}
void swap(membro *a, membro *b){
    membro c;
     c = *a;
    *a = *b;
    *b = c;
    
}
void quick_s(membro *tabelinha, int tam){
    int i, j;
    for(i = 0; i < tam; i++)
    {
        for(j = i; j < tam; j++)
        {
            if(tabelinha[i].freq > tabelinha[j].freq)
            {
                swap(&tabelinha[i], &tabelinha[j]);
            }
        }
    }
    
}
//Criar funçao de busca da letra
int Search_L(membro *tabelinha , string palavra){
	int i;
	int qntLetras = 0;
	int tam = palavra.size();
	for(i = 0; i < tam; i++)
	{
	    int pos = CharSearch(tabelinha, palavra[i], tam);
		if(pos != -1)
		{
		    tabelinha[pos].freq += 1;
		}
		else 
		{   
		    tabelinha[qntLetras].letra = palavra[i];
		    tabelinha[qntLetras].freq = 1;
		    qntLetras++;
		}
	}
	return qntLetras;
}
void imprimirTabela(membro *tabelinha, int tam){
    int i;
    for(i = 0; i < tam; i++)
    {
        cout << tabelinha[i].letra << " " << tabelinha[i].freq << endl;
    }
}
