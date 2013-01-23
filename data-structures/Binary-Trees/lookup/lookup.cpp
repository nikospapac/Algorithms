#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* BuildOneTwoThree( void );
int lookup( struct node*, int );

int main( ) {
	struct node* root = BuildOneTwoThree( );

	int search = lookup( root, 3 );

	if ( search ) {
		printf( "found\n" );
	}

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

int lookup( struct node* root, int target ) {
	if ( root == NULL ) {
		return 0;
	}

	if ( root->data == target ) {
		return 1;
	}
	else {
		if ( root->data > target ) {
			lookup( root->left, target );
		}
		else {
			lookup( root->right, target );
		}
	}
}
