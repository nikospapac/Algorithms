#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

int count( struct node*, int );
struct node *BuildOneTwoThree( void );

int main() {
	struct node *head = BuildOneTwoThree();
	int count1;

	if ( ( count1 = count( head, 2 ) ) > 0 ) {
		printf( " Ο αριθμός 2 βρέθηκε %d φορές\n", count1 );
	}
	else {
		printf( "Ο αριθμός 2 δεν βρέθηκε\n" );
	}
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

int count( struct node* head, int num ) {
	struct node* current = head;
	int count = 0;

	while ( current != NULL ) {
		if ( current->data == num ) {
			count += 1;
		}
		current = current->next;
	}
	return count;
}
