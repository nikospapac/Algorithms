#include <stdio.h>

void Swap( int a[], int, int );

int main() {
	int temp;
	int i = 0, j, N = 0, iMin;
	int array[ 5 ];

	array[ 0 ] = 5;
	array[ 1 ] = 4;
	array[ 2 ] = 1;
	array[ 3 ] = 2;
	array[ 4 ] = 6;

	N = 5;

	for ( i = 0; i < N ; ++i ) {
		iMin = i;

		for ( j = i + 1; j < N; ++j ) {
			if ( array[ j ] < array[ iMin ] ) {
				iMin = j;
			}
		}

		if ( iMin != i ) {
			Swap( array, i, iMin );
		}
		printf ( "%d\n", array[ i ] );
	}
	return 0;
}

void Swap ( int array[], int i, int j ) {
	int temp;

	temp = array[ i ];
	array[ i ] = array[ j ];
	array[ j ] = temp;
}
