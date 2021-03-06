#include <cstdio>

using namespace std;

void swap( int A[], int i, int j ) {
	int temp = A[ i ];
	A[ i ] = A[ j ];
	A[ j ] = temp;
}

void maxHeapify( int A[], int i, int N ) {
	int longest, r, l;

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
			swap( A, longest, i );
			i = longest;
		}
		else {
			break;
		}
	}
}

void buildHeap( int A[], int N ) {
	int i;
	if ( N % 2 != 0 ) {
		++N;
	}
	for ( i = N / 2; i > 0; --i ) {
		maxHeapify( A, i, N );
	}
	for ( i = 0; i < 10; ++i ) {
		printf( "%d\n", A[ i ] );
	}
}

int main() {
	int A[ 11 ] = { 0, 5, 13, 2, 25, 7, 17, 20, 8, 4 };

	buildHeap( A, 10 );
	int N = 10, i;
	for ( i = N; i > 1; --i ) {
		swap( A, i, 1 );
		--N;
		maxHeapify( A, 1, N );
	}

	for ( i = 1; i <= 10; ++i ) {
		printf( "%d ", A[ i ] );
	}
	printf( "\n" );
	return 0;
}
