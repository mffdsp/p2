
typdef struct binary_tree binary_tree;

struct binary_tree{
	int item;
	binary_tree *left;
	binary_tree *right;
};

binary_tree *create_bt(){

	return NULL;
}

int is_empty(binary_tree *bt){

	return bt == NULL;

}
//no binary
binary_tree *add_tree(int item, binary_tree *left, binary_tree *right){

	binary_tree *nova_arvore = (binary_tree*) malloc(sizeof(binary_tree));
	nova_arvore->item = item;
	nova_arvore->left = left;
	nova->arvore->right = right;
	return nova_arvore;

}
//prints functions

void print_in_order(binary_tree *arvore){

	if(!is_empty(arvore))
	{
		print_in_order(arvore->left);
		printf("%d ", arvore->item);
		print_in_order(arvore->right);
	}

}

void print_pre_order(binary_tree *arvore){

	if(!is_empty(arvore))
	{
		printf("%d ", arvore->item);
		print_in_order(arvore->left);
		print_in_order(arvore->right);
	}

}

void print_pos_order(binary_tree *arvore){

	if(!is_empty(arvore))
	{
		print_in_order(arvore->left);
		print_in_order(arvore->right);
		printf("%d ", arvore->item);
	}

}

binary_tree *binary_search(binary_search *bt, int busca){

	if(is_empty(bt) || bt->item == busca){
		return bt;
	} else if(bt->item > busca){
		return binary_search(bt->left, busca);
	} else {
		return binary_search(bt->right, busca);
	}
}

binary_tree *add_bt(binary_search *bt, int item){

	if(is_empty(bt))
	{
		bt = create_bt(item, NULL, NULL);
	} else if(bt->item > item) {	
		bt->left = add_bt(bt->left, item);
	} else { 
		bt->right = add_bt(bt->right, item);
	}
	return bt;
}



binary_tree *MaiorDireita(binary_tree *no)
{
    if(no->right != NULL)
    {
       return MaiorDireita(no->right);
    }
    else
    {
       binary_tree *aux = no;
       if(no->left != NULL)
        {
         no = no->left;
        }
        else
        {
           no = NULL;
           return aux;
        }
    }
        
}
void remove_item(binary_tree *b_raiz, int numero){
    if(b_raiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Numero nao existe na arvore!");
       return;
    }
    if(numero < b_raiz->numero)
       remove_item(b_raiz->left, numero);
    else 
       if(numero > b_raiz->numero)
          remove_item(b_raiz->right, numero);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          binary_tree *pAux = b_raiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if ((b_raiz->left == NULL) && (b_raiz->right == NULL)){         // se nao houver filhos...
                free(pAux);
                b_raiz = NULL; 
               }
          else{     // so tem o filho da right
             if (b_raiz->left == NULL){
                b_raiz = b_raiz->right;
                pAux->right = NULL;
                free(pAux); pAux = NULL;
                }
             else{            //so tem filho da left
                if (b_raiz->right == NULL){
                    b_raiz = b_raiz->left;
                    pAux->left = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{       //Escolhi fazer o maior filho direito da subarvore left.
                   pAux = Maiorright(b_raiz->left); // else
                   pAux->left = b_raiz->left;          //        pAux = Menorleft(b_raiz->right);
                   pAux->right = b_raiz->right;
                   b_raiz->left = b_raiz->right = NULL;
                   free(b_raiz);  b_raiz = pAux;  pAux = NULL;   
                   }
                }
             }
          }
}

int main(){

}
