#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
void FrontBackSplit( struct node*, struct node**, struct node** );

int main() {
	struct node* head = BuildOneTwoThree();
	struct node *front, *back;

	FrontBackSplit( head, &front, &back );

	while ( front != NULL ) {
		printf( "%d\n", front->data );
		front = front->next;
	}

	while ( back != NULL ) {
		printf( "%d\n\n", back->data );
		back = back->next;
	}
}

struct node* BuildOneTwoThree( void ) {
	struct node *head = NULL , *two = NULL, *three = NULL;

	head = malloc( sizeof( struct node ) );
	two = malloc( sizeof(struct node ) );
	three = malloc( sizeof( struct node ) );

	head->data = 1;
	head->next = two;

	two->data = 2;
	two->next = three;

	three->data = 3;
	three->next = NULL;

	return head;
}

void FrontBackSplit( struct node* source, struct node** frontRef, struct node** backRef ) {
	struct node* current = source;
	int i;
	int len = 0;
	len = Lenght( current );
	if ( len < 2 ) {
		*frontRef = source;
		*backRef = NULL;
	}
	else {
		if ( ( len % 2 ) != 0 ) {
			len = ( len / 2 ) + 1;
		}
		else { 
			len = len / 2;
		}
		for ( i = 0; i < len; ++i ) {
			current = current->next;
		}
		*frontRef = source;
		*backRef = current->next;

		current->next = NULL;
	}
}
