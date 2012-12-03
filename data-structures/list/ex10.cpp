#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildDupList( void );
void RemoveDuplicates( struct node* );

int main( ) {
	struct node* head = BuildDupList( );

	RemoveDuplicates( head );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}

	return 0;
}

struct node* BuildDupList( void ) {
	struct node *head, *head2, *second, *second2, *third, *third2;

	head = ( struct node* ) malloc( sizeof( struct node ) );
	head2 = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	second2 = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	third2 = ( struct node* ) malloc( sizeof( struct node ) );

	head->data = 1;
	head->next = head2;

	head2->data = 1;
	head2->next = second;

	second->data = 2;
	second->next = second2;

	second2->data = 2;
	second2->next = third;

	third->data = 3;
	third->next = third2;

	third2->data = 3;
	third2->next = NULL;

	return head;
}

void RemoveDuplicates( struct node* head ) {
	struct node* deletion;

	while ( head != NULL ) {
		if ( head->next->data == head->data ) {
			deletion = head->next;
			head->next = head->next->next;
			head = head->next;
			free( deletion );
		}
		else {
			head = head->next;
		}
	}
}
