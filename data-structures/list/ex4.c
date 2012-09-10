#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
int Pop( struct node** head );
int Length (struct node* );

int main() {
	int a, b, c, len;
	struct node* head = BuildOneTwoThree();

	a = Pop( &head );
	b = Pop( &head );
	c = Pop( &head );
	len = Length( head );

	printf( "%d %d %d %d\n", a, b, c, len );
}

int Pop( struct node** head ) {
	struct node* current = *head;
	struct node* next;
	int val = 0;

	if ( current != NULL ) {
		next = current->next;
		val = current->data;
		free( current );
	}
	else {
		return 0;
	}
	*head = next;
	return val;
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

int Length( struct node* head ) {
	int count = 0;
	struct node* current = head;

	while ( current != NULL ) {
		++count;
		current = current->next;
	}

	return count;
}
