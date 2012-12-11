#include <stdio.h>

void Swap( int a[], int, int );

int main() {
	int i = 0, j, k, N = 5, iMin;
	int array[ 5 ];

	array[ 0 ] = 5;
	array[ 1 ] = 4;
	array[ 2 ] = 1;
	array[ 3 ] = 2;
	array[ 4 ] = 6;

	for ( j = 0, k = 0; j < N - 1; ++j, ++k ) {

		i = j + 1;

		if ( array[ j ] > array[ i ] ) {
			Swap( array, j, i );
		}

		if ( k == N - 2 ) {
			j = -1;
			--N;
			k = -1;
		}
	}
	printf ( "%d\n%d\n%d\n%d\n%d\n", array[0], array[1], array[2], array[3], array[4] );
	return 0;
}
void Swap ( int array[], int j, int i ) {
	int temp;

	temp = array[ i ];
	array[ i ] = array[ j ];
	array[ j ] = temp;
}
