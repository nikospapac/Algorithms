#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
int GetNth( struct node*, int );

int main() {
	int num;
	struct node* head = BuildOneTwoThree();

	num = GetNth( head, 2);

	if ( num > 0 ) {
		printf( "Ο τρίτος αριθμός της λίστας είναι ο %d\n", num );
	}
	else {
		printf( "Ο αριθμός δεν υπάρχει στην λίστα	\n" );
	}
}

struct node* BuildOneTwoThree(void) {
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

int GetNth( struct node* head, int num ) {
	struct node* current = head;
	int count = 0;
	while ( current != NULL ) {
		if ( count == num ) {
			return( current->data );
		}
		current = current->next;
		++count;
	}
	return 0;
}
