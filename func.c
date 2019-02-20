//heap////heap////heap////heap////heap////heap////heap////heap////heap////heap////heap////heap////heap//

typedef struct heap heap;

struct heap
{   
    int size;
    int values[MAX];
};

heap *create_heap()
{
    heap *new_heap = (heap*) malloc(sizeof(heap));
    new_heap->size = 0;
    return new_heap;
}

int is_empty(heap *new_heap)
{
    return new_heap->size == 0;
}

int get_parents_index(heap *new_heap, int i)
{
    return i / 2;
}

int get_left_index(heap *new_heap, int i)
{
    return 2 * i;
}

int get_right_index(heap *new_heap, int i)
{
    return 2 * i + 1;
}

int item_of_heap(heap *new_heap, int i)
{
    return new_heap->values[i];
}

void swap(int *value_1, int *value_2)
{
    int temp = 0;
    temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
}

void print_heap(heap *new_heap, int i, int flag)
{
    if (i == new_heap->size + 1)
    {
        printf("\n");
        return;
    }

    if (flag == 0)
    {
        printf("%d", new_heap->values[i]);
    }

    else
    {
        printf(" | %d", new_heap->values[i]);
    }
    flag = 1;
    print_heap(new_heap, i + 1, flag);
}

void max_heapify(heap *new_heap, int i)
{
    int largest;
    int left_index = get_left_index(new_heap, i);
    int right_index = get_right_index(new_heap, i);

    if (left_index <= new_heap->size && new_heap->values[left_index] > new_heap->values[i]) 
    {
        largest = left_index;
    }

    else 
    {
        largest = i;
    }

    if (right_index <= new_heap->size && new_heap->values[right_index] > new_heap->values[largest]) 
    {
        largest = right_index;
    }

    if (largest != i) 
    {
        swap(&new_heap->values[i], &new_heap->values[largest]);
        max_heapify(new_heap, largest);
    }
}

void heap_sort(heap *new_heap)
{
    int i = 0; 
    for(i = new_heap->size; i >= 2; i--)
    {
        swap(&new_heap->values[1], &new_heap->values[i]);
        new_heap->size--;
        max_heapify(new_heap, 1); 
    } 
}

void build_max_heap(heap *new_heap)
{
    int length = new_heap->size;
    int i = 0;
    for (i = length / 2; i >= 1; i--)
    {
        max_heapify(new_heap, i);
    } 
}

int main()
{
    heap *new_heap = create_heap();
    return 0;
}

//heap////heap////heap////heap////heap////heap////heap////heap////heap////heap////heap////heap////heap////heap////heap////heap//





//AVL //AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL


typedef struct binary_tree binary_tree;

struct binary_tree {
    int item;
    int height;
    binary_tree *left, *right;
};

binary_tree *create_empty_binary_tree() {
    return NULL;
}

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right) {
    binary_tree *new_bt = (binary_tree*) malloc(sizeof(binary_tree));
    new_bt->item = item;
    new_bt->height = 1;
    new_bt->left = new_bt->right = NULL;
    return new_bt;
}

int is_empty(binary_tree *bt) {
	return bt == NULL;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int height(binary_tree *bt) {
	if (bt == NULL) {
		return -1;
	} else {
		return 1 + max(height(bt->left), height(bt->right));
	}
}

binary_tree *rotate_right(binary_tree *ubn) { 
	binary_tree *child = ubn->left; 
	binary_tree *right_child = child->right; 

	child->right = ubn; 
	ubn->left = right_child; 

	ubn->height = max(height(ubn->left), height(ubn->right)) + 1; 
	child->height = max(height(child->left), height(child->right)) + 1; 

	return child; 
} 

binary_tree *rotate_left(binary_tree *ubn) { 
	binary_tree *child = ubn->right; 
	binary_tree *left_child = child->left; 

	child->left = ubn; 
	ubn->right = left_child; 

	ubn->height = max(height(ubn->left), height(ubn->right))+1; 
	child->height = max(height(child->left), height(child->right))+1; 

	return child; 
} 

binary_tree *add(binary_tree *root, lli key) { 
	if (root == NULL) 
		return (create_binary_tree(key, NULL, NULL)); 

	if (key < root->item) {
		root->left  = add(root->left, key); 
	}
	else if (key > root->item) {
		root->right = add(root->right, key); 
	}
    else {
    	return root; 
    }
    root->height = 1 + max(height(root->left), height(root->right)); 
    int balance = is_balanced(root); 

    // If this root becomes unbalanced, then there are 4 cases 
    // Left Left Case 
    if (balance > 1 && key < root->left->item) {
    	return rotate_right(root); 
    }
    // Right Right Case 
    if (balance < -1 && key > root->right->item) {
    	return rotate_left(root); 
    }
    // Left Right Case 
    if (balance > 1 && key > root->left->item) { 
    	root->left =  rotate_left(root->left); 
    	return rotate_right(root); 
    } 
    // Right Left Case 
    if (balance < -1 && key < root->right->item) { 
    	root->right = rotate_right(root->right); 
    	return rotate_left(root); 
    } 
    return root; 
} 

int is_balanced(binary_tree *bt) { 
	if (bt == NULL) {
		return 0; 
	}
	return height(bt->left) - height(bt->right); 
} 

binary_tree *search(binary_tree *bt, lli item) {
	if ((bt == NULL) || (bt->item == item)) {
		return bt;
	} else if (bt->item > item) {
		search(bt->left, item);
	} else {
		search(bt->right, item);
	}
}

binary_tree *min_value_node(binary_tree *node) { 
	binary_tree *current = node; 

	while (current->left != NULL) {
		current = current->left; 
	}
	return current; 
} 

binary_tree *delete_node(binary_tree *root, lli key) { 
    // STEP 1: PERFORM STANDARD BST DELETE 
	if (root == NULL) {
		return root; 
	}

    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
	if (key < root->item) { 
		root->left = delete_node(root->left, key); 
	}
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
	else if(key > root->item) {
		root->right = delete_node(root->right, key);
	}
    // if key is same as root's key, then This is 
    // the node to be deleted 
	else { 
        // node with only one child or no child 
		if((root->left == NULL) || (root->right == NULL)) { 
			binary_tree *temp;
			if (root->left == NULL) {
				temp = root->right;
			} else {
				temp = root->left;
			}
            // No child case 
			if (temp == NULL) {
				temp = root; 
				root = NULL; 
			} 
			// One child case 
			else {
				*root = *temp; 
				free(temp);
                // Copy the contents of 
                // the non-empty child  
			}
		} else { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
			binary_tree *temp = min_value_node(root->right); 

            // Copy the inorder successor's data to this node 
			root->item = temp->item; 

            // Delete the inorder successor 
			root->right = delete_node(root->right, temp->item); 
		} 
	} 

    // If the tree had only one node then return 
	if (root == NULL) {
		return root; 
	}

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
	root->height = 1 + max(height(root->left), height(root->right)); 

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
	int balance = is_balanced(root); 

    // If this node becomes unbalanced, then there are 4 cases 
    // Left Left Case 
	if (balance > 1 && is_balanced(root->left) >= 0) {
		return rotate_right(root); 
	}
    // Left Right Case 
	if (balance > 1 && is_balanced(root->left) < 0) { 
		root->left =  rotate_left(root->left); 
		return rotate_right(root); 
	} 
    // Right Right Case 
	if (balance < -1 && is_balanced(root->right) <= 0) {
		return rotate_left(root); 
	}
    // Right Left Case 
	if (balance < -1 && is_balanced(root->right) > 0) { 
		root->right = rotate_right(root->right); 
		return rotate_left(root); 
	} 
	return root; 
}

void print_tree(binary_tree *bt) { // (print, visit, visit) 
	if (!is_empty(bt)) {
		printf(" ( ");
		printf("%lld ", bt->item);  

		if (bt->left == NULL) {
			printf(" () ");
		} else {
			print_tree(bt->left);
		} if (bt->right == NULL) {
			printf(" () ");
		} else {
			print_tree(bt->right);
		}
		printf(") ");
	}
}

int main() {
	int i;
	binary_tree *bt = create_empty_binary_tree();

    // bt = add(bt, i);
    // bt = search(bt, item);
    // bt = delete_node(bt, i);
    // print_tree(bt);

	return 0;
}

//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL//AVL







//REMOVER NO ARVORE //REMOVER NO ARVORE//REMOVER NO ARVORE//REMOVER NO ARVORE//REMOVER NO ARVORE
bt *min_value_node(bt *node) { 
  bt *current = node; 

  while (current->left != NULL) {
    current = current->left; 
  }
  return current; 
} 

bt *delete_node(bt *root, int key) { 
  if (root == NULL) {
    return root; 
  }

  if (key < root->item) { 
    root->left = delete_node(root->left, key); 
  } else if(key > root->item) {
    root->right = delete_node(root->right, key);
  } else { 
    if (root->left == NULL) { 
      bt *temp = root->right;
      free(root); 
      return temp; 
    } else if (root->right == NULL) { 
      bt *temp = root->left; 
      free(root); 
      return temp; 
    } 
    bt *temp = min_value_node(root->right); 
    root->item = temp->item; 
    root->right = delete_node(root->right, temp->item); 
  }
  return root; 
}
//REMOVER NO ARVORE//REMOVER NO ARVORE//REMOVER NO ARVORE//REMOVER NO ARVORE//REMOVER NO ARVORE//REMOVER NO ARVORE


//busca //busca //busca e profundidade;

bt *binary_search(bt *bt, int busca, int *profundidade){
    *profundidade += 1;//incrementa a cada busca;
    if(is_empty(bt) || bt->item == busca){
        return bt;
    } else if(bt->item > busca){
        return binary_search(bt->left, busca, profundidade);
    } else {
        return binary_search(bt->right, busca, profundidade);
    }
}

//busca //busca //busca e profundidade;




//Quest ano passado

#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree binary_tree;

struct binary_tree {
    int value;
    binary_tree *left;
    binary_tree *right;
};

binary_tree *create_binary_tree(int item, binary_tree *left, binary_tree *right) {
    binary_tree *new_bt = (binary_tree*) malloc(sizeof(binary_tree));
    new_bt->left = left;
    new_bt->right = right;
    new_bt->value = item;
    return new_bt;
}

binary_tree *create_empty_binary_tree() {
    return NULL;
}


int is_empty(binary_tree *new_bt) {   
    return new_bt == NULL;
}

void tree_to_string_pre(binary_tree *new_bt, int *str, int *index) {
    if (!is_empty(new_bt)) {
        str[*index] = new_bt->value;
        *index += 1;   
        tree_to_string_pre(new_bt->left, str, index);
        tree_to_string_pre(new_bt->right, str, index);
    }
}

void tree_to_string_pos(binary_tree *new_bt, int *str, int *index) {
    if (!is_empty(new_bt)) {
        tree_to_string_pos(new_bt->left, str, index);
        tree_to_string_pos(new_bt->right, str, index);
        str[*index] = new_bt->value;
        *index += 1;
    }
}

void tree_to_string_in(binary_tree *new_bt, int *str, int *index) {
    if (!is_empty(new_bt)) {
        tree_to_string_in(new_bt->left, str, index);
        str[*index] = new_bt->value;
        *index += 1;
        tree_to_string_in(new_bt->right, str, index);
        
    }
}

binary_tree *add(binary_tree *new_bt, int array[][2], int index) {
    if (index == -1) {
        return NULL;
    } else {
        new_bt = create_binary_tree(index, NULL, NULL);
        new_bt->left = add(new_bt->left, array, array[index][0]);
        new_bt->right = add(new_bt->right, array, array[index][1]);
        return new_bt;
    }
}

void print_tree(int *str, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (str[j] == i) {
                if (j - 1 < 0) {
                    printf("Node %d: previous = -1 next = %d\n", i, str[j + 1]);
                } else if (j == size - 1) {
                    printf("Node %d: previous = %d next = -1\n", i, str[j - 1]);
                } else {
                    printf("Node %d: previous = %d next = %d\n", i, str[j - 1], str[j + 1]);
                }  
            } 
        }
    }
}

int main() {
    int quantidade;
    scanf("%d", &quantidade);
    int array[quantidade][2];
    int i, j;

    for(i = 0; i < quantidade; i++){
        for(j = 0; j < 2; j++){
            scanf("%d", &array[i][j]);
        }
    }

    int root;
    scanf("%d", &root);
    binary_tree *bt = create_empty_binary_tree();
    bt = add(bt, array, root);

    printf("Pre Order:\n");
    int str[quantidade];
    int index = 0;
    tree_to_string_pre(bt, str, &index);
    print_tree(str, index);

    index = 0;
    printf("In Order\n");
    tree_to_string_in(bt, str, &index);
    print_tree(str, index);

    index = 0;
    printf("Post Order\n");
    tree_to_string_pos(bt, str, &index);
    print_tree(str, index);
    return 0;
}
///Quest ano passado





//another one


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree binary_tree;

struct binary_tree {
    char item;
    binary_tree *left, *right;
};

binary_tree *create_binary_tree(char item, binary_tree *left, binary_tree *right) {
    binary_tree *new_bt = (binary_tree*) malloc(sizeof(binary_tree));
    new_bt->item = item;
    new_bt->left = new_bt->right = NULL;
    return new_bt;
}

binary_tree *create_empty_binary_tree() {
    return NULL;
}

int is_empty(binary_tree *bt) {
    return bt == NULL;
}

binary_tree *add(binary_tree *root, char key) { 
    if (root == NULL) {
        return (create_binary_tree(key, NULL, NULL)); 
    } if (key < root->item) {
        root->left  = add(root->left, key); 
    } else if (key > root->item) {
        root->right = add(root->right, key); 
    } else { 
        return root; 
    }
    return root; 
} 

binary_tree *search(binary_tree *bt, char *str, int *cont) {
    if (str[*cont] == '@') {
        printf("%c", bt->item);
        *cont += 2;
        return bt; 
    } else if (str[*cont] == '*') {
        printf("%c", bt->item);
        *cont += 1;
        return bt;
    }  if (str[*cont] == '-') {
        *cont += 1;
        search(bt->left, str, cont);
    } else if (str[*cont] == '|') {
        *cont += 1;
        search(bt->right, str, cont);
    }
    return bt;
}

int main() {
    int i;
    char string[28];
    strcpy(string, "MGTCKQWAEILORUY BDFHJNPSVXZ");
    binary_tree *bt = create_empty_binary_tree();

    for (i = 0; i < 28; i++) {
        bt = add(bt, string[i]);
    }

    char str[1000];
    char letter;
    i = 0;
    while (scanf("%c", &letter) != EOF) {
        if (letter != ' ') {
            str[i] = letter;
            i++;
        }
    }

    int size = strlen(str);
    int cont = 0;

    while (cont < size - 1) {
        bt = search(bt, str, &cont);
    }

    printf("\n");
}




///entendível


///Adcionar e remover 
///Adcionar e remover 
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

void print_in_order(bt *arvore){

    printf("(");
    if(!is_empty(arvore))
    {
        printf("%d ", arvore->item);
        print_in_order(arvore->left);
        print_in_order(arvore->right);
    }
    printf(") ");
   
}

bt* construct_binary_tree(char *str, int *pos) {

    bt *btree = NULL; 
    int i = 0;
    int numInt;       
    char numStr[50]; 
    while(str[*pos] == '(') { 
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
        numStr[i] = '\0'; 
        numInt = atoi(numStr); //converte o numero string para inteiro

        btree = create_binary_tree(numInt); //cria um no com o numero inteiro
        btree->left = construct_binary_tree(str, pos);  //constroi a arvore para o no esquerdo
        btree->right = construct_binary_tree(str, pos); //constroi a arvore para o no direito
    }
    *pos += 1;
    return btree; //retorna o ponteiro para a arvore
}

void verifica(bt *bt, int *flag) {
    if (bt == NULL) {
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

bt *min_value_node(bt *node) { 
  bt *current = node; 

  while (current->left != NULL) {
    current = current->left; 
  }
  return current; 
} 

bt *delete_node(bt *root, int key) { 
  if (root == NULL) {
    return root; 
  }

  if (key < root->item) { 
    root->left = delete_node(root->left, key); 
  } else if(key > root->item) {
    root->right = delete_node(root->right, key);
  } else { 
    if (root->left == NULL) { 
      bt *temp = root->right;
      free(root); 
      return temp; 
    } else if (root->right == NULL) { 
      bt *temp = root->left; 
      free(root); 
      return temp; 
    } 
    bt *temp = min_value_node(root->right); 
    root->item = temp->item; 
    root->right = delete_node(root->right, temp->item); 
  }
  return root; 
}    

bt *add_bt(bt *bt, int item){

    if(is_empty(bt))
    {
        bt = create_binary_tree(item);
    } else if(bt->item > item) {    
        bt->left = add_bt(bt->left, item);
    } else { 
        bt->right = add_bt(bt->right, item);
    }
    return bt;
}
int main(){

    int pos = 0;
    int flag = 0;
    bt *arvore = NULL;
    //bt *arvore = construct_binary_tree(palavra, &pos);  
    arvore = add_bt(arvore, 5);
    arvore = add_bt(arvore, 2);
    arvore = add_bt(arvore, 9);
    puts("antes\n");
    print_in_order(arvore);
    arvore = delete_node(arvore, 5);
    puts("\n\ndepois do antes\n");
    print_in_order(arvore);
   }
///Adcionar e remover ///Adcionar e remover ///Adcionar e remover 


//AVL PERFEITA


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

bt *create_bt(int item){
    bt *no = (bt*) malloc(sizeof(bt));
    no->item = item;
    no->left = no->right = NULL;
    return no;
}
bt* add(bt *arv, int item){
	if (arv == NULL) {
		return create_bt(item);
	} else if (arv->item > item) {
		arv->left = add(arv->left, item);
	} else {
		arv->right = add(arv->right, item);
	}
	arv->h = h(arv);	
	bt *child = NULL;
	if (balance_factor(arv) == 2 || balance_factor(arv) == -2) {
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
	arvore = add(arvore, 5); 
	is_balanced(arvore) ? puts("yES") : puts("NO");
	arvore = add(arvore, 15); 
	is_balanced(arvore) ? puts("yES") : puts("NO");
	arvore = add(arvore, 9); 
	arvore = add(arvore, 5); 
	is_balanced(arvore) ? puts("yES") : puts("NO");
	arvore = add(arvore, 19); 
	is_balanced(arvore) ? puts("yES") : puts("NO");
	arvore = add(arvore, 51); 
	is_balanced(arvore) ? puts("yES") : puts("NO");
}
