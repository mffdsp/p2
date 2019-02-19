#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 300

typedef struct element element;
typedef struct hash_table hash_table;

struct element {
	int key;
	int value;
	element *next;
};

struct hash_table{
	element *top[MAX];
};

hash_table* create_hash_table(int primo){
	hash_table *new_hash_table = (hash_table*) malloc(sizeof(hash_table));
	int i;
	for(i = 0; i < primo; i++)
	{
		new_hash_table->top[i] = NULL;
	}
	
	return new_hash_table;
}

void put(hash_table *ht, int value, int primo)
{
	int h = value % primo;
	while(ht->top[h]->value != INT_MIN)
	{
		ht->top[h] = ht->top[h]->next;
	}
	ht->top[h]->value = value;
	return;
}

void printlist(element *head)
{
	while(head != NULL)
	{
	    printf(" -> %d", head->value);
		head = head->next;
	}
	printf("barra");
}
void printar(hash_table *ht, int primo){
	int i = 0;
	while(i < primo)
	{	
		if(ht->top[i]->value == INT_MIN)
		{
			printf("%d -> barra", i);
		}
		else printf("%d", i); printlist(ht->top[i]);
		printf("\n");
	}

}
int main(){
	int qnt;
	int valor;
	int primo, qt_elem;
	scanf("%d", &qnt);
	while(qnt--)
	{
		scanf("%d%d", &primo, &qt_elem);
		hash_table *ht = create_hash_table(primo);
		while(qt_elem--)
		{	
			scanf("%d", &valor);
			put(ht, valor, primo);
			puts("aa");
		}
		printar(ht, primo);
	}
}
