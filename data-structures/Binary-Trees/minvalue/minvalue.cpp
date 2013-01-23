#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
	int data;
	struct node* right;
	struct node* left;
};

struct node* BuildTree( void );
int minvalue( struct node* );

int main( ) {
	struct node* root = BuildTree( );

	int min = minvalue( root );

	printf( "%d\n", min );

	return 0;
}

struct node* BuildTree( void ) {
	struct node *root, *left, *right, *left2;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	left = ( struct node* ) malloc( sizeof( struct node ) );
	right = ( struct node* ) malloc( sizeof( struct node ) );
	left2 = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 5;
	root->left = left;
	root->right = right;

	left->data = 3;
	left->left = left2;
	left->right = NULL;

	left2->data = 1;
	left2->left = NULL;
	left2->right = NULL;

	right->data = 10;
	right->left = NULL;
	right->right = NULL;

	return root;
}

int minvalue( struct node* root ) {
	if( root->left == NULL ) {
		return ( root->data );
	}

	return ( minvalue( root->left ) );
}


