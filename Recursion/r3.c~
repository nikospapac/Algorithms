#include <stdio.h>

int high( int );

char A[] = "432041";

int main() {
	int num = high( 0 );

	printf( "%d\n", num );

	return 0;
}

int high ( int n ) {
	if ( A[n] == '\0' ) {
		return;
	}
	int big;

	big = high( n + 1 );

	if ( big < (A[n] - '0') ) {
		big = (A[n] - '0');
	}

	return big;
}
