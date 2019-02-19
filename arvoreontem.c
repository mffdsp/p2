#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bt bt;

struct bt{

    int item;
    bt* right; bt *left;

};

bt *create_binary_tree(int item){
    bt *no = (bt*) malloc(sizeof(bt));
    no->item = item;
    no->left = no->right = NULL;
    return no;
}

int is_empty(bt *arvore){

    return arvore == NULL;
}


bt* construct_binary_tree(char *str, int *pos) {

    bt *btree = NULL; 
    int i = 0;
    int numInt;       
    char numStr[15]; 

    while(str[*pos] == '(') { 
        *pos += 1;
    }

    if(str[*pos] == ')') { 
        *pos += 1;         
        return NULL;
    }
    else {
        while(str[*pos] != '(') {   
            numStr[i++] = str[*pos]; 
            *pos += 1;
        }
        numStr[i] = '\0'; 
        numInt = atoi(numStr); 

        btree = create_binary_tree(numInt); 
        btree->left = construct_binary_tree(str, pos);  
        btree->right = construct_binary_tree(str, pos); 
    }
    *pos += 1;
    return btree; 
}

void verifica(bt *bt, int *flag) {
    if (bt == NULL || *flag == 1) {
        return;
    }   
        if(!is_empty(bt->left)) 
        {
            if (bt->item < bt->left->item) {
                *flag = 1; //uso ponteiro para n perder valor na recursao 
            }
        }
        verifica(bt->left, flag);

        if(!is_empty(bt->right)) {
            if (bt->item > bt->right->item) {
                *flag = 1;
            }
        }
        verifica(bt->right, flag);
}
void tiraesp(char *palavra){
    int i, j = 0;
    char novap[900];
    for(i = 0;i < strlen(palavra); i++)
    {
        if(palavra[i] != ' ')
        {
           novap[j] = palavra[i];
           j++;
        }
    }
    strcpy(palavra, novap);
}
int main(){

    char palavra[900];
    int achou = 0 ; int pos = 0;
    gets(palavra);
    tiraesp(palavra);
    bt *arvore = construct_binary_tree(palavra, &pos);  
    verifica(arvore, &achou);
    achou ? puts("FALSO") : puts("VERDADEIRO");

}
