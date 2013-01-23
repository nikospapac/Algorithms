#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* BuildTree( void );
void PrintTree( struct node* );

int main( ) {
	struct node* root = BuildTree( );

	PrintTree( root );

	return 0;
}

struct node* BuildTree( ) {
	struct node *root, *second, *third, *fourth, *fifth;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );
	fifth = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 4;
	root->left = second;
	root->right = third;

	second->data = 2;
	second->left = fourth;
	second->right = fifth;

	third->data = 5;
	third->left = NULL;
	third->right = NULL;

	fourth->data = 1;
	fourth->left = NULL;
	fourth->right = NULL;

	fifth->data = 3;
	fifth->left = NULL;
	fifth->right = NULL;

	return root;
}

void PrintTree( struct node* root ) {
	if ( root == NULL ) {
		return;
	}

	PrintTree( root->left );
	printf( "%d\n", root->data );
	PrintTree( root->right );
	
}
