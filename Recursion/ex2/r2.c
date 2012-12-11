#include <stdio.h>

int factorial( int );

int main() {
	int num;

	num = factorial( 4 );

	printf( "%d\n", num );

	return 0;
}

int factorial( int n ) {
	if ( n == 1 ) {
		return 1;
	}
	int num = factorial( n - 1 );

	num = num * n;

	return num;
}
