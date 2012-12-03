#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoFour( );
void SortedInsert( struct node**, struct node* );

int main( ) {
	struct node* head = BuildOneTwoFour( );
	struct node* third = ( struct node* ) malloc( sizeof( struct node ) );
	third->data = 3;

	SortedInsert( &head, third );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}

	return 0;
}

struct node* BuildOneTwoFour( ) {
	struct node *head, *second, *fourth;

	head = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = fourth;

	fourth->data = 4;
	fourth->next = NULL;

	return head;
}

void SortedInsert( struct node** headRef, struct node* newNode ) {
	struct node* current = *headRef;

	if ( newNode->data < current->data ) {
		newNode->next = current;
		*headRef = newNode;
		return;
	}

	while ( current != NULL ) {
		if ( current->next == NULL && current->data < newNode->data ) {
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		if ( current->next->data > newNode->data ) {
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		current = current->next;
	}
}
