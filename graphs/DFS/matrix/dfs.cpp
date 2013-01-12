#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool dfs( vector<int> graph[], int N, int u, int v ) {
	bool visited[ N + 1 ];
	int i, p;
	for ( i = 0; i <= N; ++i ) {
		visited[ i ] = false;
	}
	stack<int> s;
	s.push( u - 1 );
	while ( !s.empty() ) {
		p = s.top();
		s.pop();
		visited[ p ] = true;
		for ( i = 0; i < N; ++i ) {
			if ( graph[ p ][ i ] ) {
				if ( !visited[ i ] ) {
					s.push( i );
				}
			}
		}
	}
	return visited[ v - 1 ];
}

int main() {
	FILE *fin = fopen( "dfs.in", "r" );
	FILE *fout = fopen( "dfs.out", "w" );
	int N, S, T, M;
	fscanf( fin, "%d%d%d%d", &N, &S, &T, &M );
	vector<int> graph[ N + 1 ];
	int i, j;
	for ( i = 0; i < N; ++i ) {
		for ( j = 0; j < N; ++j ) {
			graph[ i ].push_back( 0 );
		}
	}
	int u, v;

	for ( i = 0; i < M; ++i ) {
		fscanf( fin, "%d%d", &u, &v );
		graph[ u - 1 ][ v - 1 ] = 1;
	}
	if ( dfs( graph, N, S, T ) ) {
		fprintf( fout, "1\n" );
	}
	else {
		fprintf( fout, "-1\n" );
	}

	return 0;
}
