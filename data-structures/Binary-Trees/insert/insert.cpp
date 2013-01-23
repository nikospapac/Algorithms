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
struct node* Insert( struct node*, int );
void PrintTree( struct node* );
struct node* newNode( int );

int main( ) {
	struct node* root = BuildOneTwoThree( );

	root = Insert( root, 5 );

	PrintTree( root );

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

void PrintTree( struct node* root ) {
	if ( root == NULL ) {
		return;
	}

	printf( "%d\n", root->data );
	PrintTree( root->left );
	PrintTree( root->right );
}

struct node* Insert( struct node* root, int data ) {

	if ( root == NULL ) {
		return( newNode( data ) ); 
	}

	else {
		if ( root->data < data ) {
			root->right = Insert( root->right, data );
		}
		else {
			root->left = Insert( root->left, data );
		}
		return root;
	}
}

struct node* newNode( int data ) {
	struct node* node = ( struct node* ) malloc( sizeof( struct node ) );

	node->data = data;
	node->right = NULL;
	node->left = NULL;

	return node;
}
