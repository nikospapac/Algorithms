	#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
void FrontBackSplit( struct node*, struct node**, struct node** );
struct node* SortedMerge ( struct node* , struct node* );
void MoveNode( struct node**, struct node** );
int Lenght( struct node* );

int main() {
	struct node* head = BuildOneTwoThree();
	struct node *a, *b;

	FrontBackSplit(head, &a, &b );
	


	head = SortedMerge( a, b );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}
}

void FrontBackSplit ( struct node* source, struct node** frontRef, struct node** backRef ) {
	struct node* current = source;
	int i;
	int len = 0;
	len = Lenght(current);
	if ( len < 2 ) {
		*frontRef = source;
		*backRef = NULL;
	}
	else {
		if ( len % 2 != 0 ) {
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

struct node* BuildOneTwoThree( void ) {
	struct node *one, *two, *three;

	one = malloc( sizeof( struct node ) );
	two = malloc( sizeof( struct node ) );
	three = malloc( sizeof( struct node ) );

	one->data = 4;
	one->next = two;
	
	two->data = 86;
	two->next = three;

	three->data = 7;
	three->next = NULL;

	return one;
}

struct node* SortedMerge( struct node* a, struct node* b ) {
	struct node dummy;
	struct node* tail = &dummy;

	dummy.next = NULL;

	while ( 1 ) {
		if ( a == NULL ) {
			tail->next = b;
			break;
		}
		else if ( b == NULL ) {
			tail->next = b;
			break;
		}
	if ( a->data <= b->data ) {
		MoveNode( &( tail->next ), &a );
	}
	else {
		MoveNode( &( tail->next ), &b );
	}
	tail = tail->next;
	}
	return ( dummy.next );
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

int Lenght ( struct node* current ) {
	int count = 0;

	while ( current != NULL ) {
		++count;
		current = current->next;
	}

	return count;
}
