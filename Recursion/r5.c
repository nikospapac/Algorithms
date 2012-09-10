#include <stdio.h>

int sum( int );

char A[] = "8243842";

int main() {
	int num = sum( 0 );

	printf( "%d\n", num );

	return 0;
}

int sum( int n ) {
	if ( A[n] == '\0' ) {
		return;
	}

	int num = ( A[n] - '0' );
	int i = sum( n + 1 );
	num = num + i;

	return num;
}
