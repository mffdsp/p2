#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct bt bt;
struct bt {
	int item;
	int h;
	bt* left;
	bt* right;
};

int max(int a, int b){

	return (a > b) ? a : b;
}

int h(bt *bt){

	if (bt == NULL) {
		return -1;
	} else {
		return 1 + max(h(bt->left), h(bt->right));
	}
}

int is_balanced(bt *arv){

	int bf = h(arv->left) - h(arv->right);
	return (     (-1 <= bf) && (bf <= 1)       );
}

int is_empty(bt *arvore){

    return arvore == NULL;
}


int balance_factor(bt *bt){
	if (bt == NULL) {
		return 0;
	} else if ((bt->left != NULL) && (bt->right != NULL)) {
		return (bt->left->h - bt->right->h);
	} else if ((bt->left != NULL) && (bt->right == NULL)) {
		return (1 + bt->left->h);
	} else {
		return (-bt->right->h - 1);
	}
}

bt* rotate_left(bt *arv){
	bt *subtree_root = NULL;
	if (arv != NULL && arv->right != NULL) {
		subtree_root = arv->right;
		arv->right = subtree_root->left;
		subtree_root->left = arv;
	}
	subtree_root->h = h(subtree_root);
	arv->h = h(arv);
	return subtree_root;
}

bt *create_bt(int item){
    bt *no = (bt*) malloc(sizeof(bt));
    no->item = item;
    no->left = no->right = NULL;
    return no;
}
bt* rotate_right(bt *arv)
{
	bt *subtree_root = NULL;
	if (arv != NULL && arv->left != NULL) {
		subtree_root = arv->left;
		arv->left = subtree_root->right;
		subtree_root->right = arv;
	}
	subtree_root->h = h(subtree_root);
	arv->h = h(arv);
	return subtree_root;
}

bt *add_n(bt *arv, int item){

    if(is_empty(arv))
    {
        arv = create_bt(item);
    } else if(arv->item > item) {    
        arv->left = add_n(arv->left, item);
    } else { 
        arv->right = add_n(arv->right, item);
    }
    return arv;
}


void print_pre_order(bt *bt)
{
    printf(" (");
    if (!is_empty(bt))
    {
        printf(" %d ", bt->item);
        
            print_pre_order(bt->left);
            print_pre_order(bt->right);
    }
    printf(") ");
}



bt* add(bt *arv, int item, int *flag, bt *aux){
	aux = add_n(aux, item);
	if (arv == NULL) {
		return create_bt(item);
	} else if (arv->item >= item) {
		arv->left = add(arv->left, item, flag, aux);
	} else {
		arv->right = add(arv->right, item, flag, aux);
	}
	arv->h = h(arv);	
	bt *child = NULL;
	
	
	if (balance_factor(arv) == 2 || balance_factor(arv) == -2) {
	        if(flag == 0)
	        {
	            *flag = 1;
		    	puts("Antes de ajustar balanceamento...");
			    print_pre_order(aux);
			    puts("");
	        }
			
		if (balance_factor(arv) == 2) {
			child = arv->left;
		if (balance_factor(child) == -1) {
			arv->left = rotate_left(child);
		}
		arv = rotate_right(arv);
		} else if (balance_factor(arv) == -2) {
			child = arv->right;
			if (balance_factor(child) == 1) {
			arv->right = rotate_right(child);
			}
			arv = rotate_left(arv);
		}
	}
return arv;
}

int main(){

	bt *arvore = NULL;
	bt *aux = NULL;
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int flag = 0;
		arvore = add(arvore, n, &flag, aux);
		aux = arvore;
		printf("Adcionando %d\n", n);
		if(flag == 0)
		{
			puts("continua avl");
			print_pre_order(arvore);
			printf("\n");
		}
		else 
		{
			puts("DEPOIS DE COISA");
			print_pre_order(arvore);
			printf("\n");

		}
		printf("AQUI CARAI : %d",arvore->item);
	}
}
