#include <cstdio>

using namespace std;

int main() {
	long long int num, i;
	int count = 0;
	int k, array[ 100000 ];
	scanf( "%lld", &num );
	for ( i = 1, k = 0; i <= num / 2; ++i ) {
		if ( num % i == 0 ) {
			array[ k++ ] = i;
			++count;
		}
	}
	printf( "%d\n", count );

	for ( i = 0; i < k; ++i ) {
		printf( "%d\n", array[ i ] );
	}

	return 0;
}
