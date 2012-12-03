#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
int Pop( struct node** );

int main( ) {
	struct node* head = BuildOneTwoThree( );
	int a, b, c;

	a = Pop( &head );
	b = Pop( &head );
	c = Pop( &head );

	printf( "%d %d %d\n", a, b, c );

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

int Pop( struct node** headRef ) {
	struct node* current = *headRef;
	int num;

	*headRef = current->next;
	num = current->data;

	free( current );
	return num;
}
