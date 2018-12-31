#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int BIGO = 0;
void set(int *v2){
	int i;
	for(i = 0; i < 20; i++)
	{
		v2[i] = -1;
	}
}
void pescaSorting(int *v, int *v2){
	int i;
	for(i = 0; i < 10; i++)
	{
		int indice = v[i];
		//printf("%d\n", indice);
		v2[indice] = v[i];
	}
	int j = 0;
	for(i = 0; i < 20; i++)
	{
		if(v2[i]!=-1)
		{
			v[j] = v2[i];
			j++;
		}
	    BIGO++;
	}
	//printf("%d ", v[0]);
}
void imprimir(int *v){
	int i;
	for(i = 0; i < 10; i++)
	{
		printf("%d ", v[i]);
	}
}
int main(){
	int v[10] = {574,51,25,65,94,18,10,15,48,108};
	int v2[20];
	set(v2);
	pescaSorting(v,v2);
    imprimir(v);
    BIGO == 20 ? printf("\n BIG O = O(n)", BIGO) : puts("Passou de n");
    return 0;
}
