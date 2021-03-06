#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool dfs( vector<int> graph[], int N, int u, int v ) {
	bool visited[ N + 1 ];
	int i;
	for ( i = 0; i < N; ++i ) {
		visited[ i ] = false;
	}
	int p, k;
	stack<int> s;
	s.push( u );
	while ( !s.empty() ) {
		p = s.top();
		s.pop();
		visited[ p ] = true;
		for ( i = 0; i < graph[ p ].size(); ++i ) {
			k = graph[ p ][ i ];
			if ( !visited[ k ] ) {
				s.push( k );
			}
		}
	}
	return visited[ v ];
}

int main() {
	FILE *fin = fopen( "dfs.in", "r" );
	FILE *fout = fopen( "dfs.out", "w" );
	int N, S, T, M;
	fscanf( fin, "%d%d%d%d", &N, &S, &T, &M );
	int i, u, v;
	vector<int> graph[ N + 1 ];
	for ( i = 0; i < M; ++i ) {
		fscanf( fin, "%d%d", &u, &v );
		graph[ u ].push_back( v );
	}

	if ( dfs( graph, N, S, T ) ) {
		fprintf( fout, "1\n" );
	}
	else {
		fprintf( fout, "-1\n" );
	}

	return 0;
}
