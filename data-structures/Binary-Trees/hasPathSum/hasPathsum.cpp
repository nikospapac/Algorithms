#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* BuildTree( void );
int hasSumPath( struct node*, int sum );

int main( ) {
	struct node* root = BuildTree( );

	int found = hasSumPath( root, 9 );

	if ( found ) {
		printf( "found\n" );
	}
	else {
		printf( "not found\n" );
	}

	return 0;
}

struct node* BuildTree( void ) {
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

int hasSumPath( struct node* root, int sum ) {
	
	if ( root == NULL ) {
		return false;
	}
	sum = sum - ( root->data );

	if ( sum == 0 && root->left == NULL && root->right == NULL ) {
		return true;
	}
	if ( ( hasSumPath( root->left, sum ) ) == true ) {
		return true;
	}
	else if ( ( hasSumPath( root->right, sum ) ) == true ) {
		return true;
	}
	else {
		return false;
	}
}
