int pares(int a){
	return a%2==0;
}
int impares(int a){
	return !(a%2==0);
}
int primos(int a){
	int primo = 1, i;
	for(i = 2; i <= sqrt(a); i++)
	{
		if(a%i==0)
		{
			primo = 0;
		}
	}
	return primo && a!=1;
}
int filtro(int (*funcao)(int), int *v, int tam){
	int i = 0;
	for(i = 0; i < tam; i++)
	{
		if(funcao(v[i]))
		{
			printf("%d ", v[i]);
		}
	}
}
void main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int i;
    filtro(primos,a,10);
}
