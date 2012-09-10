#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* ShuffleMerge( struct node*, struct node* );
struct node* BuildOneTwoThree( void );

int main() {
	struct node* a = BuildOneTwoThree();
	struct node* b = BuildOneTwoThree();
	struct node* head = ShuffleMerge( a, b );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}
}

struct node *ShuffleMerge( struct node* a, struct node* b ) {
	struct node* head = NULL;
	struct node* current;
	int count = 0;
	struct node* aC = a;
	struct node* bC = b;

	if ( a == NULL || b == NULL ) {
		return;
	}

	while ( a != NULL && b != NULL ) {
		if ( count == 0 ) {
			a = a->next;
			b = b->next;
			head = aC;
			current = head;
			head->next = bC;
			head = head->next;
			count = 1;
		}
		else {
			a = a->next;
			b = b->next;
			head->next = aC;
			head->next->next = bC;
			head = head->next->next;
		}
		aC = a;
		bC = b;
	}
	return current;
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
