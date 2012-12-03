#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
int GetNth( struct node*, int );

int main( ) {
	struct node* head = BuildOneTwoThree( );
	int number;

	number = GetNth( head, 0 );

	printf( "%d\n", number ) ;

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

int GetNth( struct node* head, int number ) {
	int count = 0;

	while ( head != NULL ) {
		if ( count == number ) {
			return ( head->data );
		}
		head = head->next;
		++count;
	}
	return 0;
}
