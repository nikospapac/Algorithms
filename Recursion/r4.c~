#include <stdio.h>

int min( int );

char A[] = "824384";

int main() {
	int num = min( 0 );

	printf( "%d\n", num );

	return 0;
}

int min ( int n ) {
	if ( A[n+1] == '\0' ) {
		return (A[n] - '0');
	}
	int small;

	small = min( n + 1 );

	if ( small > (A[n] - '0') ) {
		small = (A[n] - '0');
	}

	return small;
}
