#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

void InsertNth( struct node**, int, int );

int main( ) {
	struct node* head = NULL;

	InsertNth( &head, 0, 1 );
	InsertNth( &head, 1, 3 );
	InsertNth( &head, 2, 2 );

	while( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}

	return 0;
}

void InsertNth( struct node** headRef, int pos, int data ) {
	struct node* current = *headRef;
	struct node* newNode = ( struct node* ) malloc( sizeof( struct node ) );
	newNode->data = data;
	int count = 1;
	if ( *headRef == NULL || pos == 0) {
		newNode->next = *headRef;
		*headRef = newNode;
		return;
	}

	while ( current != NULL ) {
		if( count == pos ) {
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		++count;
		current = current->next;
	}
}
