#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void RemoveDuplicates( struct node* );
struct node* BuildOneOneThree( void );

int main() {
	struct node* head = BuildOneOneThree();

	RemoveDuplicates( head );

	while ( head != NULL ) {
		printf( "%d\n", head->data );
		head = head->next;
	}

	return 0;
}

struct node* BuildOneOneThree( void ) {
	struct node *head, *one, *three;

	head = malloc( sizeof( struct node ) );
	one = malloc( sizeof( struct node ) );
	three = malloc ( sizeof( struct node ) );

	head->data = 1;
	head->next = one;

	one->data = 1;
	one->next = three;

	three->data = 3;
	three->next = NULL;

	return head;
}

void RemoveDuplicates( struct node* head ) {
	struct node* next, current = head;
	int prevnum;

	if ( current == NULL ) {
		return;
	}
	while ( current->next != NULL ) {
		if ( current->data == current->next->data ) {
			next = current->next->next;
			free(current->next);
			current->next = next;
		}
		else {
			current = current->next;
		}
	}
}
