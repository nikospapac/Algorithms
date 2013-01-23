#include <cstdio>
#include <vector>

using namespace std;

vector< int > A;

void swap( int i, int j ) {
	int temp = A[ i ];
	A[ i ] = A[ j ];
	A[ j ] = temp;
}

void maxHeapify( int i ) {
	int longest;
	int l, r;
	int N = A.size();
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
			swap( i, longest );
			i = longest;
		}
		else {
			break;
		}
	}
}

int max() {
	return A[ 0 ];
}
int exmax() {
	int m = A[ 0 ];
	A[ 0 ] = A[ A.size() ];
	A.pop_back();

	maxHeapify( 0 );

	return m;
}

void insert( int key ) {
	A.push_back( key );
	int i = A.size();
	while ( i > 1 && A[ i / 2 ] < A[ i ] ) {
		swap( i / 2, i );
		i = i / 2;
	}
}

int main() {
	A.push_back( 0 );
	int n, i;
	for ( i = 0; i < 9; ++i ) {
		scanf( "%d", &n );
		insert( n );
	}
	for ( i = A.size(); i >= 0; --i ) {
		maxHeapify( i );
	}
	for ( i = 0; i < 9; ++i ) {
		printf( "%d ", exmax() );
	}
	printf( "\n" );

	return 0;
}
