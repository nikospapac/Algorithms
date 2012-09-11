#include <cstdio>

using namespace std;

int binsearch( int[], int, int );


int main() {
	int array[ 6 ] = { 5, 7, 28, 41, 42, 107 };

	int place = binsearch( array, 7, 6 );

	printf( "%i\n", array[place] );

	return 0;
}

int binsearch( int array[], int num, int N ) {
	int len;

	if ( array[N] == num ) {
		return N;
	}
	else if ( array[ N + 1 ]  == num ) {
		return N + 1;
	}
	else if ( array[ N - 1 ] == num ) {
		return N - 1;
	}

	if ( array[ N / 2 ] > num ) {
		len = 0;
	}
	else {
		len = N / 2;
	}

	N = binsearch( array, num, N / 2 );

	return N;
}
