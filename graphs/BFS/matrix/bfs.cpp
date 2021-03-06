#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;

bool bfs( vector<int> A[], int u, int v ) {
	bool visited[ N + 1 ];
	int i, p, k;
	for ( i = 0; i <= N; ++i ) {
		visited[ i ] = false;
	}
	queue<int> q;
	q.push( u - 1 );
	while ( !q.empty() ) {
		p = q.front();
		q.pop();
		visited[ p ] = true;
		for ( i = 0; i < N; ++i ) {
			if ( A[ p ][ i ] ) {
				if ( !visited[ i ] ) {
					q.push( i );
				}
			}
		}
	}
	return visited[ v - 1 ];
}

int main() {
	FILE *fin = fopen( "bfs.in", "r" );
	FILE *fout = fopen( "bfs.out", "w" );
	int S, T, M;
	fscanf( fin, "%d%d%d%d", &N, &S, &T, &M );
	vector<int> A[ N + 1 ];
	int i, j, u, v;
	for ( i = 0; i < N; ++i ) {
		for ( j = 0; j < N; ++j ) {
			A[ i ].push_back( 0 );
		}
	}

	for ( i = 0; i < M; ++i ) {
		fscanf( fin, "%d%d", &u, &v );
		A[ u - 1 ][ v - 1 ] = 1;
	}

	if ( bfs( A, S, T ) ) {
		fprintf( fout, "1\n" );
	}
	else {
		fprintf( fout, "-1\n" );
	}

	return 0;
}
