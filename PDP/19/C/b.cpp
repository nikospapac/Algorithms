#include <cstdio>

using namespace std;

int bsearch( int N, int S ) {
	int mid, count = 1;
	int beg = 1, end = N;

	while ( beg < end ) {
		mid = ( beg + N ) / 2;

		if ( mid >= S ) {
				return count + ( S - beg  + 1 );
		}
		else {
			beg = mid + 1;
			++count;
		}
	}

}

int main() {
	int t, N, S;
	scanf( "%d", &t );

	while ( t > 0 ) {
		scanf( "%d%d", &N, &S );

		printf( "%d\n", bsearch( N, S ) );
		--t;
	}

	return 0;
}
