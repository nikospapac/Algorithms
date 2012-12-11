#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( void );
void DeleteList( struct node** );

int main( ) {
	struct node* head = BuildOneTwoThree( );

	DeleteList( &head );

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

void DeleteList( struct node** headRef ) {
	struct node *current, *deletion;

	current = deletion = *headRef;

	while ( current != NULL ) {
		deletion = current->next;
		free( current );
		current = deletion;
	}
	*headRef = NULL;
}
