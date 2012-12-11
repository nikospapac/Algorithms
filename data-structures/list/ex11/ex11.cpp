#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
void MoveNode( struct node**, struct node** );

int main( ) {
	struct node* a = BuildOneTwoThree( );
	struct node* b = BuildOneTwoThree( );

	MoveNode( &a, &b );

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

struct node* BuildOneTwoThree( void ) {
	struct node *head, *second, *third;

	head = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	return head;
}

void MoveNode( struct node** aRef, struct node** bRef ) {
	struct node* current = *bRef;

	*bRef = current->next;

	current->next = *aRef;
	*aRef = current;
}
