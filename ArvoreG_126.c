#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	char pai[99];
	char nome[99];
	int  qf;
	char filhos[300][300];
}dados;

int check_name(dados *arvore, char *aux_str, int total){
	int j;
	for(j = 0; j < total; j++)
	{
		if(strcmp(aux_str, arvore[j].nome)==0)
		{	
			return j;
		}
	}
	return -1;
}

int main() {
	int i = 0, j, qnt, total = 0;
	int aloc_mult = 1;
	char aux_str[300];
	dados *arvore;
	arvore = (dados*) malloc(sizeof(dados));
	scanf("%d", &qnt);
	while(qnt--)
	{	
	    getchar();
		scanf("%s ", aux_str);
		i = check_name(arvore, aux_str, total);
		if(i==-1)
		{
			strcpy(arvore[total].nome, aux_str);
			scanf("%[^\n]s",arvore[total].filhos[arvore[total].qf]);
			arvore[total].qf++;
			total++;
			aloc_mult++;
			arvore = (dados*) realloc(arvore, sizeof(dados) * (aloc_mult));
			
		}
		else{

			scanf("%[^\n]s",arvore[i].filhos[arvore[i].qf]);
			arvore[i].qf++;

		}

	}
	return 0;
}
