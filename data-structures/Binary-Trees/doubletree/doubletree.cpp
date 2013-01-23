#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode( int );
struct node* BuildTree( void );
void DoubleTree( struct node* );
void PrintTree( struct node* );

int main( ) {
	struct node* root = BuildTree( );

	DoubleTree( root );

	PrintTree( root );

	return 0;
}

struct node* BuildTree( void ) {
	struct node *root, *second, *third;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 2;
	root->left = second;
	root->right = third;

	second->data = 1;
	second->left = NULL;
	second->right = NULL;

	third->data = 3;
	third->left = NULL;
	third->right = NULL;

	return root;
}

struct node* newNode( int data ) {
	struct node* node = ( struct node* ) malloc( sizeof( struct node ) );

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void PrintTree( struct node* root ) {
	if ( root == NULL ) {
		return;
	}

	PrintTree( root->left );
	printf( "%d\n", root->data );
	PrintTree( root->right );
}

void DoubleTree( struct node* root ) {
	if ( root == NULL ) {
		return;
	}

	struct node* save;

	DoubleTree( root->left );
	save = root->left;
	root->left = newNode( root->data );
	root->left->left = save;
	DoubleTree( root->right );
	
}
