#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int data;
	struct node* next;
};

void InsertNth( struct node**, int, int );

int main() {
	struct node* head = NULL;

	InsertNth( &head, 0, 13 );
	InsertNth( &head, 1, 42 );
	InsertNth( &head, 2, 5 );

	while( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}
}

void InsertNth( struct node** headRef, int index, int data ) {
	struct node* current = *headRef;
	int count;
	struct node* newNode = malloc( sizeof( struct node ) );
	newNode->data = data;

	if ( index == 0 ) {
		newNode = *headRef;
		*headRef = newNode;
	}
	else {
		for ( count = 0; count < index-1; count++ ) {
			assert( current != NULL );
			current = current->next;
		}
		assert( current != NULL );

		newNode = current;
		current = newNode;
	}	
}

