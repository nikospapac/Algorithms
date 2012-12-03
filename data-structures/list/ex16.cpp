#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneFourFive( );
struct node* BuildTwoThreeSix( );
struct node* InsertSort( struct node*, struct node* );
void PushEnd( struct node**, int );

int main( ) {
	struct node* a = BuildOneFourFive( );
	struct node* b = BuildTwoThreeSix( );

	struct node* head = InsertSort( a, b );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}

	return 0;
}

struct node* BuildOneFourFive( ) {
	struct node *head, *fourth, *fifth;

	head = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );
	fifth = ( struct node* ) malloc( sizeof( struct node ) );

	head->data = 1;
	head->next = fourth;

	fourth->data = 4;
	fourth->next = fifth;

	fifth->data = 5;
	fifth->next = NULL;

	return head;
}

struct node* BuildTwoThreeSix( ) {
	struct node *second, *third, *sixth;

	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	sixth = ( struct node* ) malloc( sizeof( struct node ) );

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = sixth;

	sixth->data = 6;
	sixth->next = NULL;

	return second;
}

struct node* InsertSort( struct node* a, struct node* b ) {
	struct node* newList = NULL;

	if ( a == NULL ) {
		return b;
	}
	else if ( b == NULL ) {
		return a;
	}

	if ( a->data < b->data ) {
		PushEnd( &newList, a->data );
		a = a->next;
	}
	else {
		PushEnd( &newList, b->data );
		b = b->next;
	}

	while ( a != NULL && b != NULL ) {
		if ( a->data  < b->data ) {
			PushEnd( &newList, a->data );
			a = a->next;
		}
		else {
			PushEnd( &newList, b->data );
			b = b->next;
		}
	}

	if ( a == NULL && b == NULL ) {
		return newList;
	}
	else if ( a == NULL ) {
		while ( b != NULL ) {
			PushEnd( &newList, b->data );
			b = b->next;
		}
		return newList;
	}
	else if ( b == NULL ) {
		while ( a != NULL ) {
			PushEnd( &newList, a->data );
			a = a->next;
		}
		return newList;
	}
}

void PushEnd( struct node** headRef, int data ) {
	struct node* newNode;
	struct node* current = *headRef;
	newNode = ( struct node* ) malloc( sizeof( struct node ) );

	newNode->data = data;
	newNode->next = NULL;

	if ( *headRef == NULL ) {
		*headRef = newNode;
		return;
	}

	while ( current->next != NULL ) {
		current = current->next;
	}
	current->next = newNode;
}
