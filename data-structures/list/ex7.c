#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* BuildRandom( void );
void InsertSort( struct node** );
void SortedInsert( struct node**, struct node* );

int main() {
	struct node* head = BuildRandom();
	
	InsertSort( &head );

	while( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}
	return 0;
}

struct node* BuildRandom ( void ) {
	struct node *one, *two, *four;

	one = malloc( sizeof( struct node ) );
	one->data = 7;

	two = malloc( sizeof( struct node ) );
	two->data = 4;

	four = malloc( sizeof( struct node ) );
	four->data = 27;

	one->next = two;
	two->next = four;
	four->next = NULL;

	return one;
}

void InsertSort( struct node** headRef ) {
	struct node* current = *headRef;
	struct node* result = NULL;
	struct node* next;

	while ( current != NULL ) {
		next = current->next;
		SortedInsert( &result, current );
		current = next;
	}
	*headRef = result;
}

void SortedInsert( struct node** headRef, struct node* newNode ) {
	struct node* current = *headRef;
	if ( current == NULL ) {
		newNode->next = current;
		current = newNode;
	}
	else {
		while ( current->next != NULL && current->next->data<newNode->data ) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}
