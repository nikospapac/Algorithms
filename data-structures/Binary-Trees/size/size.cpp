#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* BuildOneTwoThree( void );
int size( struct node* );

int main( ) {
	struct node* root = BuildOneTwoThree( );

	int s = size( root );

	printf( "%d\n", s );

	return 0;
}

struct node* BuildOneTwoThree( void ) {
	struct node *root, *left, *right;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	left = ( struct node* ) malloc( sizeof( struct node ) );
	right = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 2;
	root->left = left;
	root->right = right;

	left->data = 1;
	left->left = NULL;
	left->right = NULL;

	right->data = 3;
	right->left = NULL;
	right->right = NULL;

	return root;
}

int size( struct node* root ) {
	int count = 1;
	if ( root == NULL ) {
		return 0;
	}

	count += size( root->left );
	count += size( root->right );

	return count;
}
