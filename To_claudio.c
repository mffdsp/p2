#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

typedef struct queue pq;
typedef struct node list;
typedef struct hash_table hash;
typedef struct element element;

struct queue
{
	list *head;
};

struct node
{
	unsigned char c;
	long int freque;
	list *left;
	list *right;
	list *next;
};

struct element
{
  unsigned char binary[100];
};

struct hash_table
{
  element *table[256];
};

hash* create_dictionary()
{
  hash *new_hash = (hash*) malloc(sizeof(hash));
  int i;
  for (i = 0; i < 256; i++)
  {
    new_hash->table[i] = NULL;
  }
  return new_hash;
}

void print(list *aux)
{
    if(aux!= NULL)
    {
        printf("%d %c\n",aux->freque, aux->c);
        print(aux->left);
        print(aux->right);
    }
}

void print_in_order(list *bt)
{
    if (bt != NULL) {
        print_in_order(bt->left);
        printf("%c", bt->c);
        print_in_order(bt->right);
        
    }
}

pq *create_queue()
{
	pq *queue = (pq*)malloc(sizeof(pq));
	queue->head = NULL;
	return queue;
}

list* dequeue(pq *queue)
{
    if (queue == NULL) {
        printf("Priority Queue underflow");
        return NULL;
    } else {
        list *node = queue->head;
        queue->head = queue->head->next;
        node->next = NULL;
        return node;
    }
}

void huff_tree(pq *queue)
{
	list *aux = queue->head;
	list *aux2 = aux->next;
	hash *hs = create_dictionary();
	while(aux2 != NULL)
	{
		enqueue(queue, '*', aux->freque + aux2->freque, aux, aux2);
		dequeue(queue);
		dequeue(queue);
		aux = queue->head;
		aux2 = aux->next;
	}
	
	list *hff = queue->head;
	//print(hff);

	list *huffman = queue->head;
	printf("Tree	-	");
    print_in_order(huffman);
    printf("\n");
	unsigned char binary[20] = {0};
	long long int i=0;
	Hash(hs, queue->head, binary, &i);
	print_dictionary(hs);
}

void enqueue(pq *pq,unsigned char c, long int freq, list *left, list *right)
{
    list *current = (list*) malloc(sizeof(list));
    current->c = c;
    current->freque = freq;
    current->left = left;
    current->right = right;

    if (pq->head == NULL || freq < pq->head->freque) {
        current->next = pq->head;
        pq->head = current;
    } else {
        list *current_l = pq->head;
        while (current_l->next != NULL && current_l->next->freque < freq) {
            current_l = current_l->next;
        }
        current->next = current_l->next;
        current_l->next = current;
    }
}

void make_q(int *freq, pq * queue)
{
	int i;
	for(i = 0; i < 256; i++)
	{
		if (freq[i] != 0)
		{
		    enqueue(queue, i, freq[i], NULL, NULL);
		}
	}
	huff_tree(queue);
}

unsigned char* add_left(unsigned char *binary, long long int *i)
{
  binary[i[0]] = '0';
  i[0]++;
  return binary;
}

unsigned char* add_right(unsigned char *binary, long long int *i)
{
  binary[i[0]] = '1';
  i[0]++;
  return binary;
}

void put_string_in_hash(hash *ht, unsigned char index, unsigned char *binary)
{
  element *new_element = (element*) malloc(sizeof(element));
  strcpy(new_element->binary, binary);
  ht->table[index] = new_element;
}

void Hash(hash *ht, list *huff, unsigned char *binary, long long int *i)
{
  if(huff != NULL)
  {
    if(huff->left == NULL && huff->right == NULL)
    {
      put_string_in_hash(ht, huff->c, binary);

      binary[*i] = NULL;
      *i -= 1;
      return;
    }

    binary = add_left(binary,i);
    Hash(ht, huff->left, binary, i);

    binary = add_right(binary,i);
    Hash(ht, huff->right, binary, i);

    binary[*i] = NULL;
    *i -= 1;
  }
}

void print_dictionary(hash *ht)
{
	int i;
  for(i = 0;i < 255;i++)
  {
    if(ht->table[i] != NULL)
    {
      printf("%c	-	%s\n",i, ht->table[i]->binary);
    }
  }
}

int main()
{
	unsigned char c[256];
	pq *queue = create_queue();
	int freq[256] = {0};
	int i,j;
	scanf("%s", c);
	
	for (j = 0; j < strlen(c); ++j)
	{
		freq[c[j]]++;	
	}
	make_q(freq, queue);
	
	return 0;
}
