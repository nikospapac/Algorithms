#include <cstdio>

using namespace std;

int binsearch( int[], int, int );


int main() {
	int array[ 6 ] = { 5, 7, 28, 41, 42, 107 };

	int place = binsearch( array, 100, 6 );

	if ( place > 0 ) {
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

	if ( array[N] == num ) {
		return N;
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


	return N;
}
