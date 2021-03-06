#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node* next;
};

void SortedInsert( struct node **, struct node * );
struct node *BuildOneTwoFour( void );

int main() {
	struct node* head = BuildOneTwoFour();
	struct node* newNode = malloc( sizeof( struct node ) );
	newNode->data = 3;

	SortedInsert( &head, newNode );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}
}

struct node* BuildOneTwoFour( void ) {
	struct node *one, *two, *four;

	one = malloc( sizeof( struct node ) );
	one->data = 1;

	two = malloc( sizeof( struct node ) );
	two->data = 2;

	four = malloc( sizeof( struct node ) );
	four->data = 4;

	one->next = two;
	two->next = four;
	four->next = NULL;

	return one;
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
