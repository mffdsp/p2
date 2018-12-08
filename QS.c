
//O código possuia erro nas linhas 18 e 19, pois os indices a e/ou b, poderiam assumir valores abaixo de 0 ou acima do tamanho do array;
//Tbm, para casos com numeros repetidos a correção está linha 24;



void quick_sort(int *v, int size){

	if (size <=1){
		return ;
	}
	else 
	{
	    int pivot=v[size/2];
	    int a=0;
	    int b=size-1;

	    while (a < b){
	    	while(v[a]<pivot && a<size) a++; // 18
	    	while(v[b]>pivot && b>=0) b--;   // 19
	    	if (a<=b)
		{
	    		swap(&v[a],&v[b]);
			a++;          		//24
		}
		    
	    }
	    quick_sort(v,b);
	    quick_sort(v+a,size-a);
	}
}
