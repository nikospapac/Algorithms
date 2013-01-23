#include <cstdio>

using namespace std;

void swap( int A[], int i, int j ) {
	int temp = A[ i ];
	A[ i ] = A[ j ];
	A[ j ] = temp;
}

void maxHeapify( int A[], int i, int N ) {
	int longest;
	int l, r;
	while ( 1 ) {
		l = i * 2;
		r = i * 2 + 1;
		if ( l <= N && A[ l ] > A[ i ] ) {
			longest = l;
		}
		else {
			longest = i;
		}
		if ( r <= N && A[ r ] > A[ longest ] ) {
			longest = r;
		}
		if ( longest != i ) {
			swap( A, i, longest );
			i = longest;
		}
		else {
			break;
		}
	}
}

int main() {
	int A[ 15 ] = { 0, 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0 };
	int i;
	for ( i = 1; i < 15 / 2; ++i ) {
		if ( A[ i * 2 ] > A[ i ] ) {
			maxHeapify( A, i, 15 );
			continue;
		}
		if ( A[ i * 2 + 1 ] > A[ i ] ) {
			maxHeapify( A, i, 15 );
		}
	}
	for ( i = 1; i < 15; ++i ) {
		printf( "%d ", A[ i ] );
	}
	printf( "\n" );

	return 0;
}
