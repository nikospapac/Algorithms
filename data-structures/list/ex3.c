#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void DeleteList( struct node** );
struct node* BuildOneTwoThree( void );

int main() {
	struct node* head = BuildOneTwoThree();

	DeleteList( &head );

	if ( head == NULL ) {
		printf( "Διαγραφή επιτυχής\n" );
	}
	else {
		printf( "error\n" );
	}
}

void DeleteList( struct node** head ) {
	struct node* current = *head;
	struct node* next;

	while( current != NULL ) {
		next = current->next;
		free ( current );
		current = next;
	}
	*head = NULL;
}

struct node* BuildOneTwoThree( void ) {
	struct node *head = NULL , *two = NULL, *three = NULL;

	head = malloc( sizeof( struct node ) );
	two = malloc( sizeof( struct node ) );
	three = malloc( sizeof( struct node ) );

	head->data = 1;
	head->next = two;

	two->data = 2;
	two->next = three;

	three->data = 3;
	three->next = NULL;

	return head;
}
