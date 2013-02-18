#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

struct node {
	int u;
	int dist;
};

int m;
vector< int > *graph;

void dfs( int u ) {
	stack< node > s;
	s.push( ( node ) { u, 1 } );
	while ( !s.empty() ) {
		node p = s.top();
		s.pop();
		for ( int i = 0; i < graph[ p.u ].size(); ++i ) {
			int k = graph[ p.u ][ i ];
			s.push( ( node ) { k, p.dist + 1 } );
			if ( p.dist + 1 > m ) {
				m = p.dist + 1;
			}
		}
	}
}

int main() {
	FILE *fin = fopen( "scidinner.in", "r" );
	FILE *fout = fopen( "scidinner.out", "w" );
	int N, M;
	fscanf( fin, "%d%d", &N, &M );
	int i, u, v;
	m = 1;
	bool deg[ N + 1 ];
	graph = new vector< int >[ N + 1 ];
	for ( i = 0; i <= N; ++i ) {
		deg[ i ] = false;
	}
	for ( i = 0; i < M; ++i ) {
		fscanf( fin, "%d%d", &u, &v );
		if ( u != v ) {
			graph[ u ].push_back( v );
			deg[ v ] = true;
		}
	}
	for ( i = 1; i <= N; ++i ) {
		if ( !deg[ i ] ) {
			dfs( i );
		}
	}
	fprintf( fout, "%d\n", m );
	return 0;
}

