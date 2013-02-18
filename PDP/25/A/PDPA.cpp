#include <cstdio>

using namespace std;

int main() {
	FILE *fin = fopen( "seti.in", "r" );
	FILE *fout = fopen( "seti.out", "w" );
	int N;
	fscanf( fin, "%d", &N );
	long long int array[ N ], A[ N ];
	int i, j, k = 0;
	int count = 0, save = 1;
	for ( i = 0; i < N; ++i ) {
		fscanf( fin, "%lld", array + i );
	}
	
	for ( i = 1; i < N; ++i ) {
		j = i;
		while ( j + i >= N ) {
			--j;
		}

		if ( array[ i ] % 2 == 0 ) {
			save = 0;
		}
		while ( j > 0 ) {
			if ( array[ i - j ] == array[ i + j ] ) {
				if ( array[ i - j ] < ( array[ i ] / 2 ) + save ) {
					A[ k ] = i + 1;
					++k;
					++count;
					break;
				}
			}
			--j;
		}
		save = 1;
	}

	fprintf( fout, "%d\n", count );
	for ( i = 0; i < count; ++i ) {
		fprintf( fout, "%lld\n", A[ i ] );
	}
	return 0;
}
