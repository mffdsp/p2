#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int bin_search(int *a, int valor, int inicio, int fim){
	int meio = (inicio+fim) / 2;
	if(a[meio]==valor) return meio+1; 
	else if(a[meio]<valor) { bin_search(a,valor,meio+1, fim); }
	else if(a[meio]>valor) { bin_search(a,valor,inicio, meio-1); }
	else if(inicio>fim){return -1;}

}
void trocar(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
void bub_sort(int *a, int n){
	int i,j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(a[i]<a[j])
			{
				trocar(&a[i], &a[j]);
			}
		}
	}
}
int main() {
	int n_marm = 1, n_consul = 1, i = 1;
	int saida, count = 1;
	int *marm = (int*) malloc(sizeof(int));
	int *consul = (int*) malloc(sizeof(int));
	while(1)
	{
	    scanf("%d%d", &n_marm, &n_consul);
	    if(n_marm==0 && n_consul==0) {break;}
		printf("CASE# %d:\n", count);
		for(i = 0; i < n_marm; i++)
		{
		    marm = (int *) realloc(marm, sizeof(int) * (i+1));
			scanf("%d", &marm[i]);
		}
		for(i = 0; i < n_consul; i++)
		{
		    consul = (int *) realloc(consul, sizeof(int) * (i+1));
			scanf("%d", &consul[i]);
		}
		bub_sort(marm,n_marm);
// 		for(i = 0; i < n_marm; i++)
// 		{
// 		    printf("%d--", marm[i]);
// 		}
// 		printf("i = %d\n", i);
		for(i = 0; i < n_consul; i++)
		{
			saida = bin_search(marm,consul[i],0,n_marm-1);
			if(saida==-1)
			{
				printf("%d not found\n", consul[i]);
			}
			else printf("%d found at %d\n", consul[i], saida);
		}
		free(marm);
		free(consul);
		count++;
	}
	//Ta correto, só n ta certo.
	return 0;
}
