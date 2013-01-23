#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* BuildTreeA( void );
struct node* BuildTreeB( void );
int sametree( struct node*, struct node* );

int main( ) {
	struct node* a = BuildTreeA( );
	struct node* b = BuildTreeB( );

	int check = sametree( a, b );

	if ( check ) {
		printf( " The trees are same " );
	}
	else {
		printf( " The trees are not the same " );
	}
}

struct node* BuildTreeA( void ) {
	struct node *root, *second, *third;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 2;
	root->left = second;
	root->right = third;

	second-> data = 1;
	second->left = NULL;
	second->right = NULL;

	third->data = 3;
	third->left = NULL;
	third->right = NULL;

	return root;
}

struct node* BuildTreeB( void ) {
	struct node *root, *second, *third;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 2;
	root->left = second;
	root->right = NULL;

	second->data = 1;
	second->left = NULL;

	second->right = NULL;
	third->data = 4;
	third->left = NULL;
	third->right = NULL;
}

int sametree( struct node* a, struct node* b ) {
	if ( ( a == NULL && b != NULL ) || ( a != NULL && b == NULL ) ) {
		return false;
	}
	if ( a == NULL && b == NULL ) {
		return true;
	}
	

	if ( sametree( a->left, b->left ) == true && sametree( a->right, b->right ) == true ) {
		if ( a->data == b->data ) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}
