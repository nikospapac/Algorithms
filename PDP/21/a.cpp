#include <cstdio>
#include <cmath>

using namespace std;

unsigned long long int factorial( int N ) {
	unsigned long long int num = 1;

	for ( int i = 2; i <= N; ++i ) {
		num *= i;
	}
	return num;
}

int main() {
	unsigned long long int a, b, vr, N, M;

	scanf( "%lld%lld%lld%lld%lld", &N, &M, &vr, &a, &b );
	unsigned long long int fact = factorial( N );
	unsigned long long int sum = ( M * ( M + 1 ) ) / 2;
	unsigned long long int ans = vr + ( a * ( fact / 1000000 ) ) - ( b * sum );
	printf( "%lld\n", ans );

	return 0;
}
