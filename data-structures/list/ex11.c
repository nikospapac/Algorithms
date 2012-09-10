#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
void MoveNode( struct node**, struct node** );

int main() {
	struct node* a = BuildOneTwoThree();
	struct node* b = BuildOneTwoThree();

	MoveNode( &a, &b );

	while ( a != NULL ) {
		printf( "%d\n\n", a->data );
		a = a->next;
	}
	while ( b != NULL ) {
		printf( "%d\n", b->data );
		b = b->next;
	}
	return 0;
}

struct node* BuildOneTwoThree( void ) {
	struct node *one, *two, *three;

	one = malloc( sizeof( struct node ) );
	two = malloc( sizeof( struct node ) );
	three = malloc( sizeof( struct node ) );

	one->data = 1;
	one->next = two;
	
	two->data = 2;
	two->next = three;

	three->data = 3;
	three->next = NULL;

	return one;
}

void MoveNode( struct node** destRef, struct node** sourceRef ) {
	if ( *sourceRef == NULL ) {
		return;
	}
	else {
		struct node* source = *sourceRef;
		struct node* dest = *destRef;
		struct node* save = source->next;

		source->next = dest;
		dest = source;

		source = save;

		*sourceRef = source;
		*destRef = dest;
	}
}
