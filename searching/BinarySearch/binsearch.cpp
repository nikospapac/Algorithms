#include <cstdio>

using namespace std;

int binsearch( int[], int, int );


int main() {
	int array[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int place = binsearch( array, 10, 10 );

	if ( place >= 0 ) { 
		printf( "%i\n", array[place] );
	}
	else {
		printf( "number not found\n" );
	}

	return 0;
}

int binsearch( int array[], int num, int N ) {
	int len;
	int save = N;

	if ( array[N / 2] > num ) {
		if ( array[N] == num ) {
			if ( N == 1 ) {
				return N;
			}
			else {
				return N;
			}
		}
		else if ( array[ N + 1 ]  == num ) {
			return N + 1;
		}
		else if ( array[ N - 1 ] == num ) {
			return N - 1;
		}

		if ( N == 1 ) {
			return -1;
		}

		N = binsearch( array, num, N / 2 );
	}
	else {
		save = N / 2;

		while ( save < N ) {
			if ( array[save] == num ) {
				return save;
			}
			++save;
		}
	}

	return N;
}
