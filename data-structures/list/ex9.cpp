#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneToFive( );
int Length( struct node* );
void FrontBackSplit( struct node*, struct node**, struct node** );

int main( ) {
	struct node* head = BuildOneToFive( );
	struct node *a, *b;

	FrontBackSplit( head, &a, &b );

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

struct node* BuildOneToFive( ) {
	struct node *head, *second, *third, *fourth, *fifth;

	head = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );
	fifth = ( struct node* ) malloc( sizeof( struct node ) );

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = fourth;

	fourth->data = 4;
	fourth->next = fifth;

	fifth->data = 5;
	fifth->next = NULL;

	return head;
}

int Length( struct node* head ) {
	int count = 0;

	while ( head != NULL ) {
		head = head->next;
		++count;
	}

	return count;
}

void FrontBackSplit( struct node* source, struct node** aRef, struct node** bRef ) {
	int len = Length( source );
	int count = 1;

	*aRef = source;

	if ( len % 2 == 0 ) {
		len = len / 2;
	}
	else {
		len = len / 2 + 1;
	}

	while ( count < len ) {
		source = source->next;
		++count;
	}

	*bRef = source->next;
	source->next = NULL;
}
