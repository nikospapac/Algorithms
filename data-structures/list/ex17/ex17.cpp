#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree( );
void Reverse( struct node** );
int Length( struct node* );

int main( ) {
	struct node* head = BuildOneTwoThree( );

	Reverse( &head );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}

	return 0;
}

struct node* BuildOneTwoThree( ) {
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

void Reverse( struct node** headRef ) {
	struct node *save, *next, *current;

	current = *headRef;
	int len = Length( current );
	int count = 2;

	save = current;
	current = current->next;
	next = current->next;
	save->next = NULL;
	current->next = save;
	save = current;
	current = next;

	while ( count < 3 ) {
		next = current->next;
		current->next = save;
		save = current;
		if ( next == NULL ) {
			break;
		}
		current = next;
		++count;
	}
	*headRef = current;
}

int Length( struct node* head ) {
	struct node* current = head;
	int count = 0;

	while ( current != NULL ) {
		current = current->next;
		++count;
	}
	return count;
}
