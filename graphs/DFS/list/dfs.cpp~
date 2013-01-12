#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dfsSearch( vector<int> graph[], bool visited[], int u, int v ) {
	if ( graph[ u ].size() == 0 ) {
		return 0;
	}
	int i, p;
	for ( i = 0; i < graph[ u ].size(); ++i ) {
		p = graph[ u ][ i ];
		if ( !visited[ p ] ) {
			dfsSearch( graph, visited, p, v );
			visited[ p ] = true;
		}
	}
	return visited[ v ];
}

bool dfs( vector<int> graph[], int N, int u, int v ) {
	bool visited[ N + 1 ];
	int i;
	for ( i = 0; i < N; ++i ) {
		visited[ i ] = false;
	}
	return dfsSearch( graph, visited, u, v );
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
