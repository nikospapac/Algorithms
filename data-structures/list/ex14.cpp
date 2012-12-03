#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneThreeFive( void );
struct node* BuildTwoFourSix( void );
struct node* SortedMerge( struct node*, struct node* );

int main( ) {
	struct node* a = BuildOneThreeFive( );
	struct node* b = BuildTwoFourSix( );
	struct node* head = SortedMerge( a, b );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}

	return 0;
}

struct node* BuildOneThreeFive( void ) {
	struct node *head, *third, *fifth;

	head = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	fifth = ( struct node* ) malloc( sizeof( struct node ) );

	head->data = 1;
	head->next = third;

	third->data = 3;
	third->next = fifth;

	fifth->data = 5;
	fifth->next = NULL;

	return head;
}

struct node* BuildTwoFourSix( void ) {
	struct node *second, *fourth, *sixth;

	second = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );
	sixth = ( struct node* ) malloc( sizeof( struct node ) );

	second->data = 2;
	second->next = fourth;

	fourth->data = 4;
	fourth->next = sixth;

	sixth->data = 6;
	sixth->next = NULL;

	return second;
}

struct node* SortedMerge( struct node* a, struct node* b ) {
	struct node *current, *save;

	if ( a == NULL ) {
		return b;
	}
	if ( b == NULL ) {
		return a;
	}

	if ( a->data < b->data ) {
		current = a;
		a = a->next;
	}
	else {
		current = b;
		b = b->next;
	}
	save = current;

	while ( a != NULL && b != NULL ) {
		if ( a->data < b->data ) {
			current->next = a;
			a = a->next;
			current = current->next;
		}
		else {
			current->next = b;
			b = b->next;
			current = current->next;
		}
	}

	if ( a == NULL && b == NULL ) {
		return save;
	}
	else if ( a == NULL ) {
		current->next = b;
		return save;
	}
	else if ( b == NULL ) {
		current->next = a;
		return save;
	}
}
