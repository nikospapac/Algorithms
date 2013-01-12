#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool bfs( vector<int> graph[], int V, int u, int v ) {
	bool visited[ V + 1 ];
	int i, k;
	for ( i = 0; i <= V; ++i ) {
		visited[ i ] = false;
	}
	queue<int> q;
	q.push( u );
	while ( !q.empty() ) {
		int p = q.front();
		q.pop();
		visited[ p ] = true;
		for ( i = 0; i < graph[ p ].size(); ++i ) {
			k = graph[ p ][ i ];
			if ( !visited[ k ] ) {
				q.push( k );
			}
		}
	}
	return visited[ v ];
}

int main() {
	FILE *fin = fopen( "bfs.in", "r" );
	FILE *fout = fopen( "bfs.out", "w" );
	int N, S, T, M;
	fscanf( fin, "%d%d%d%d", &N, &S, &T, &M );
	int u, v;
	vector<int> graph[ N + 1 ];
	for ( int i = 0; i < M; ++i ) {
		fscanf( fin, "%d%d", &u, &v );
		graph[ u ].push_back( v );
		graph[ v ].push_back( u );
	}

	if ( bfs( graph, N, S, T ) ) {
		fprintf( fout, "1\n" );
	}
	else {
		fprintf( fout, "-1\n" );
	}

	return 0;
}
