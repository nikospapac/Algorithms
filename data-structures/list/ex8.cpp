#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( );
void Append( struct node**, struct node** );

int main( ) {
	struct node* a = BuildOneTwoThree( );
	struct node* b = BuildOneTwoThree( );

	Append( &a, &b );

	while ( a != NULL ) {
		printf( "%d\n", a->data );
		a = a->next;
	}

	return 0;
}

struct node* BuildOneTwoThree( ) {
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

void Append( struct node** aRef, struct node** bRef ) {
	struct node* current = *aRef;

	while ( current->next != NULL ) {
		current = current->next;
	}

	current->next = *bRef;

	*bRef = NULL;
}
