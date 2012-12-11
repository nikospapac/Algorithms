#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildDupList( void );
void MoveNode( struct node**, struct node** );
void AlternatingSplit( struct node*, struct node**, struct node** );

int main( ) {
	struct node* head = BuildDupList( );
	struct node *a, *b;

	AlternatingSplit( head, &a, &b );

	while ( a != NULL ) {
		printf( "%d\n", a->data );
		a = a->next;
	}

	printf( "\n" );

	while ( b != NULL ) {
		printf( "%d\n", b->data );
		b = b->next;
	}

	return 0;
}

struct node* BuildDupList( void ) {
	struct node *head, *second, *third, *fourth;

	head = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );

	head->data = 1;
	head->next = second;

	second->data = 1;
	second->next = third;

	third->data = 2;
	third->next = fourth;

	fourth->data = 2;
	fourth->next = NULL;

	return head;
}

void MoveNode( struct node** aRef, struct node** bRef ) {
	struct node* current = *bRef;

	*bRef = current->next;

	current->next = *aRef;
	*aRef = current;
}

void AlternatingSplit( struct node* source, struct node** aRef, struct node** bRef ) {
	int count = 1;
	*aRef = NULL;
	*bRef = NULL;
	while( source != NULL ) {
		if ( count % 2 == 0 ) {
			MoveNode( bRef, &source );
		}
		else {
			MoveNode( aRef, &source );
		}
		++count;
	}
}
