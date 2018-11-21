#include <stdio.h>

typedef int zezinho;

int impar(zezinho a){return a%2;}
int par(zezinho a){return !(a%2);}
int primo(zezinho a){
	  zezinho j;
	  zezinho primo = 1;
		primo = 1;
		for(j = 2; j <= sqrt(a) ; j++)
		{
			if((a%j)==0 || a==1 || a==0)
			{
				primo = 0;
                break;
			}
		}
    return primo;
}
zezinho filtro(zezinho *v, void *(function)(zezinho*), zezinho tam){
    int j = 0;
    for(j = 0; j < tam; j++)
    {
      if( function(v[j]) )
      {
      printf("%d ", v[j]);
      }
    }
}
zezinho main(){
	zezinho *num, i = 0;
	num = (zezinho*) malloc(sizeof(double));
	while(scanf("%d", &num[i])!=EOF)
	{   
		 i++;
		 realloc(num, i*sizeof(double));
	} 
	filtro(num,primo, i);
	
}
