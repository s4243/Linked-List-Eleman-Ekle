#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void push(struct Node**head_ref,int new_data)//basa eleman ekleme
{
	//O(1) MAL�YET� VARD�R
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void insertAfter(struct Node* prev_node,int new_data)//bir dugumden sonra eklemek
{
	//O(1) MAL�YET� VARD�R
	if (prev_node==NULL)//�nce ki veri bos
	{
		printf("Verilen onceki ifade bos olamaz");
		return;
	}
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
void append(struct Node** head_ref, int new_data)//sonuna yeni dugum ekle
{
	//O(N) MAL�YET� VARD�R N=BAGLANTILI L�STE DUGUM SAYISI
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node* last = *head_ref; 
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
void printList(struct Node* node)//listenin bas�ndan sonana kadar yazd�r�r
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}
int main()
{
	struct Node* head = NULL;
	append(&head, 6);//sonuna eleman ekleme
	push(&head, 7); //basa eleman ekleme
	push(&head, 1); 
	append(&head, 4);
	insertAfter(head, 8);//head 1 elemandan sonra demek yani 2 eleman olarak 8 ekle
	//head->next de 3 eleman olarak ekle demek
	printf("\n Created Linked list is: ");
	printList(head);//tum elemanlar� yazd�r

	return 0;
}