

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Essa função recebe a string com a arvore em notacao de parenteses
 * e um ponteiro para inteiro para construir a arvore binaria a 
 * partir da string
 */

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
void print_pre_order(bt *arvore){

    if(!is_empty(arvore))
    {
        printf("%d ", arvore->item);
        print_pre_order(arvore->left);
        print_pre_order(arvore->right);
    }
   

}
void print_in_order(bt *arvore){

    if(!is_empty(arvore))
    {
       
        print_in_order(arvore->left);
        printf("%d ", arvore->item);
        print_in_order(arvore->right);
    }
   

}

void print_pos_order(bt *arvore){

    if(!is_empty(arvore))
    {
        print_pos_order(arvore->left);
        print_pos_order(arvore->right);
        printf("%d ", arvore->item);
    }


}


bt* construct_binary_tree(char *str, int *pos) {

    bt *btree = NULL; //ponteiro para a arvore
    int i = 0;
    int numInt;       //numero do no (inteiro)
    char numStr[50];  //numero do no (string)
 
    while(str[*pos] == '(') { //ignora os parenteses abrindo
        *pos += 1;
    }

    if(str[*pos] == ')') { //se encontrar parentese fechando, retorna null
        *pos += 1;         // pois o ponteiro eh nulo
        return NULL;
    }
    else {
        while(str[*pos] != '(') {    //se for diferente de abre parenteses
            numStr[i++] = str[*pos]; //le o numero string
            *pos += 1;
        }
        numStr[i] = '\0'; //finalizando a string com '/0'
        numInt = atoi(numStr); //converte o numero string para inteiro

        btree = create_binary_tree(numInt); //cria um no com o numero inteiro
        btree->left = construct_binary_tree(str, pos);  //constroi a arvore para o no esquerdo
        btree->right = construct_binary_tree(str, pos); //constroi a arvore para o no direito
    }
    *pos += 1;
    return btree; //retorna o ponteiro para a arvore
}


int main(){

    char palavra[900] = "(12(7(3()())(10()(11()())))(23(17()())(31()())))"; 
    int pos = 0;
    bt *arvore = construct_binary_tree(palavra, &pos);

    print_pre_order(arvore);
    puts("PRE ORDEM");
    
    print_pos_order(arvore);
    puts("POS ORDEM");
    
    print_in_order(arvore);
    puts("IN ORDEM");

}
