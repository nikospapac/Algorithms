#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void Append( struct node**, struct node** );
struct node* BuildRandom( void );

int main() {
	struct node* a = BuildRandom();
	struct node* b = BuildRandom();

	Append( &a, &b );

	while ( a != NULL ) {
		printf( "%d\n", a->data );
		a = a->next;
	}
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

void Append( struct node** aRef, struct node** bRef ) {
	if( *aRef == NULL ) {
		*aRef = *bRef;
	}
	else {
		struct node* current = *aRef;
		while ( current->next != NULL ) {
			current = current->next;
		}
		current->next = *bRef;
	}
	*bRef = NULL;
}
