#include <stdio.h>

int fibonacci ( int, int, int );

int main() {
	int len = fibonacci( 20, 1, 0 );

	printf( "%d\n", len );

	return 0;
}

int fibonacci( int n, int num, int prevnum ) {
	int next;
	if ( n == 0 ) {
		return;
	}

	next = num + prevnum;
	prevnum = num;
	num = next;
	num = fibonacci ( n-1, num, prevnum );

	return num;
}
