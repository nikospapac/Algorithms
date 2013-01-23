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
	int A[ 10 ] = { 0, 5, 3, 17, 10, 84, 19, 6, 22, 9 };
	int i;
	for ( i = 10 / 2; i > 0; --i ) {
		maxHeapify( A, i, 10 );
	}
	for ( i = 1; i < 10; ++i ) {
		printf( "%d ", A[ i ] );
	}
	printf( "\n" );

	return 0;
}
