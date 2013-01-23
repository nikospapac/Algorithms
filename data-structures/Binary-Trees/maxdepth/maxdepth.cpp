#include <cstdio>
#include <cstdlib>
#include <cstring>

struct node {
	int data;
	struct node* right;
	struct node* left;
};

struct node* Build1235( );
int maxdepth( struct node* );

int main( ) {
	struct node* root = Build1235( );

	int depth = maxdepth( root );

	printf( "%d\n", depth );

	return 0;
}

struct node* Build1235( ) {
	struct node *root, *second, *third, *fourth;

	root = ( struct node* ) malloc( sizeof( struct node ) );
	second = ( struct node* ) malloc( sizeof( struct node ) );
	third = ( struct node* ) malloc( sizeof( struct node ) );
	fourth = ( struct node* ) malloc( sizeof( struct node ) );

	root->data = 2;
	root->left = second;
	root->right = third;

	second->data = 1;
	second->left = NULL;
	second->right = NULL;

	third->data = 3;
	third->right = fourth;
	third->left = NULL;

	fourth->data = 5;
	fourth->left = NULL;
	fourth->right = NULL;

	return root;
}

int maxdepth( struct node* root ) {
	int count1 = 1, count2 = 1;

	if ( root == NULL ) {
		return 0;
	}

	count1 += maxdepth( root->left );
	count2 += maxdepth( root->right );

	if ( count1 >= count2 ) {
		return count1;
	}
	else {
		return count2;
	}

}
