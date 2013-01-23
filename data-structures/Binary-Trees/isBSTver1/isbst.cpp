#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

int minvalue( struct node* );
int maxvalue( struct node* );
int isBST( struct node* );
struct node* BuildTree();

int main() {
	struct node* root = BuildTree();

	if ( isBST( root ) ) {
		printf( "is BST\n" );
	}

	return 0;
}

struct node* BuildTree() {
	struct node *root, *second, *third, *fourth, *fifth;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );
	fifth = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 5;
	root->left = second;
	root->right = third;

	second->data = 2;
	second->left = fourth;
	second->right = fifth;

	third->data = 6;
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

int minvalue( struct node* root ) {
	if( root->left == NULL ) {
		return ( root->data );
	}

	return ( minvalue( root->left ) );
}

int maxvalue( struct node* root ) {
	if( root->right == NULL ) {
		return root->data;
	}

	return ( maxvalue( root->right ) );
}

int isBST( struct node* root ) {
	if ( root == NULL ) {
		return true;
	}

	if ( root->left != NULL && maxvalue( root->left ) > root->data ) {
		return false;
	}

	if ( root->right != NULL && minvalue( root->right ) <= root->data ) {
		return false;
	}

	if ( isBST( root->left ) == true && isBST( root->right ) == true ) {
		return true;
	}
	else {
		return false;
	}
}
