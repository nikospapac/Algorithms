#include <cstdio>

using namespace std;

int findmin( int [], int );

int main( ) {
	int array[ 4 ] = { 6, 4, 5, 7 };

	int min = findmin( array, 4 );

	printf( "%d\n", min );
	return 0;
}

int findmin( int array[], int n ) {
	if ( n == 0 ) {
		return array[ n ];
	}
	
	if ( array[ n - 1 ] < findmin( array, n - 1 ) ) {
		return array[ n - 1 ];
	}
	else {
		return findmin( array, n - 1 );
	}
}
