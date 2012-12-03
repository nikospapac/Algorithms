#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
struct node* ShuffleMerge( struct node*, struct node* );

int main( ) {
	struct node* a = BuildOneTwoThree( );
	struct node* b = BuildOneTwoThree( );

	struct node* head = ShuffleMerge( a, b );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
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

struct node* ShuffleMerge( struct node* a, struct node* b ) {
	struct node* current = NULL, *save;
	int count = 2;
	current = a;
	save = current;
	a = a->next;

	while( a != NULL && b != NULL ) {
		if ( count % 2 == 0 ) {
			current->next = b;
			b = b->next;
			current = current->next;
		}
		else {
			current->next = a;
			a = a->next;
			current = current->next;
		}
		++count;
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
