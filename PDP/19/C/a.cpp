#include <cstdio>

using namespace std;

void anoi( int N, char* a, char* b, char* c ) {
	if ( N == 1 ) {
		printf( "%s %s\n", a, c );
	}
	else {
		anoi( N - 1, a, c, b );
		printf( "%s %s\n", a, c );
		anoi( N - 1, b, a, c );
	}
}

int main() {
	int N;
	scanf( "%d", &N );
	char a[ 2 ] = "A";
	char b[ 2 ] = "B";
	char c[ 2 ] = "C";
	anoi( N, a, b, c );

	return 0;
}
