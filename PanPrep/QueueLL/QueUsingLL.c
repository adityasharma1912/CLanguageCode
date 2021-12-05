#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_t
{
	int val;
	struct Node_t *next;
}Node;

void enqueue(int);
void dequeue();
int isFull();
int isEmpty();

Node *head = NULL;
Node *tail = NULL;
int size = 0;
int max_size = 0;

void enqueue(int val){
	if(isFull()){
		printf("Queue is already full, can't insert item with value = %d\n",val);
		return;
	}

	Node *new_node = (Node *) malloc(sizeof(Node));
	memset(new_node, 0x0, sizeof(Node));
	new_node->val = val;
	if(isEmpty()){
		head = new_node;
		tail = new_node;
		size++;
		return;
	}

	tail->next = new_node;
	tail = tail->next;
	size++;
	return;
}

void dequeue(){
	if(isEmpty()){
		printf("Queue is already empty, can't dequeue more items\n");
		return;
	}

	Node *node_to_remove = head;
	if(head == tail){
		//last element in the queue
		head = NULL;
		tail = NULL;
	} else{
		head = head->next;
	}
	free(node_to_remove);
	size--;
	return;
}

int isEmpty(){
	return (head == NULL && tail  == NULL);
}

int isFull(){
	return (size == max_size);
}

void print_queue(){
	Node *tmp = head;

	while(tmp!=NULL){
		printf("%d-> ", tmp->val);
		tmp = tmp->next;
	}
	printf("x\n");
	return;
}

void delete_queue(){
	if(isEmpty()){
		return;
	}

	Node *tmp = head;
	while(tmp!=NULL){
		Node *next = tmp->next;
		free(tmp);
		tmp = next;
	}
	return;
}

int main(int argc, char **argv){
	max_size = 3;

	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	printf("size = %d\n", size);
	print_queue();
	dequeue();
	printf("size = %d\n", size);
	print_queue();
	enqueue(60);
	printf("size = %d\n", size);
	print_queue();

	printf("sizeof(Node *) = %lu\n", sizeof(Node *));
	printf("sizeof(Node) = %lu\n", sizeof(Node));

	delete_queue();
	return 0;
}

