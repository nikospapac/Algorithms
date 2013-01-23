#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void mirror( struct node* );
void PrintTree( struct node* );
struct node* BuildTree( void );

int main( ) {
	struct node* root = BuildTree( );

	mirror( root );

	PrintTree( root );

	return 0;
}

struct node* BuildTree( void ) {
	struct node *root, *second, *third, *fourth, *fifth;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );
	fifth = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 5;
	root->left = second;
	root->right = third;

	second->data = 3;
	second->left = fourth;
	second->right = fifth;

	fourth->data = 2;
	fourth->left = NULL;
	fourth->right = NULL;
	
	fifth->data = 4;
	fifth->left = NULL;
	fifth->right =NULL;

	third->data = 7;
	third->left = NULL;
	third->right = NULL;

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

void mirror( struct node* root ) {
	if ( root->left == NULL && root->right == NULL ) {
		return;
	}
	struct node *save;

	mirror( root->left );
	save = root->left;
	root->left = root->right;
	root->right = save;
	mirror( root->left );
}
