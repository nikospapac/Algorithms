#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

void FrontBackSplit( struct node*, struct node**, struct node** );
struct node* SortedMerge( struct node* a, struct node* b );
struct node* BuildRandList( );
void MergeSort( struct node** );
int Length( struct node* );

int main( ) {
	struct node* head = BuildRandList( );

	MergeSort( &head );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}

	return 0;
}

struct node* BuildRandList( ) {
	struct node *head, *second, *third, *fourth;

	head = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );

	head->data = 42;
	head->next = second;

	second->data = 6;
	second->next = third;

	third->data = 72;
	third->next = fourth;

	fourth->data = 47;
	fourth->next = NULL;

	return head;
}

void MergeSort( struct node** headRef ) {
	struct node* save = *headRef;
	struct node* current = *headRef;
	struct node* a;
	struct node* b;
	if ( current->next == NULL || current == NULL ) {
		return;
	}
	
	FrontBackSplit( current, &a, &b );
	MergeSort( &a );
	MergeSort( &b );

	*headRef = SortedMerge( a, b );
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


void FrontBackSplit( struct node* source, struct node** aRef, struct node** bRef ) {
	int len = Length( source );
	int count = 1;

	*aRef = source;

	if ( len % 2 == 0 ) {
		len = len / 2;
	}
	else {
		len = len / 2 + 1;
	}

	while ( count < len ) {
		source = source->next;
		++count;
	}

	*bRef = source->next;
	source->next = NULL;
}

int Length( struct node* head ) {
	int count = 0;

	while ( head != NULL ) {
		head = head->next;
		++count;
	}

	return count;
}
