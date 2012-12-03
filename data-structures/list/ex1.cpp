#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
int Count( struct node*, int );

int main( ) {
	struct node* head = BuildOneTwoThree( );
	int nfound;

	nfound = Count( head, 2 );

	printf( "%d\n", nfound );
	

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

int Count( struct node* head, int num ) {
	int nfound = 0;
	while ( head != NULL ) {
		if ( head->data == num ) {
			++nfound;
		}
		head = head->next;
	}
	return nfound;
}
