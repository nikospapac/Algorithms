#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void PrintTree( struct node* );
struct node* BuildOneTwoThree( void );

int main( ) {
	struct node* root = BuildOneTwoThree( );

	PrintTree( root );

	return 0;
}

struct node* BuildOneTwoThree( void ) {
	struct node *root, *left, *right;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	left = ( struct node* ) malloc( sizeof( struct node ) );
	right = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 2;
	root->right = right;
	root->left = left;

	right->data = 3;
	right->right = NULL;
	right->left = NULL;

	left->data = 1;
	left->right = NULL;
	left->left = NULL;

	return root;
}

void PrintTree( struct node* root ) {
	if ( root == NULL ) {
		return;
	}

	printf( "%d\n", root->data );

	PrintTree( root->left );
	PrintTree( root->right );
}
