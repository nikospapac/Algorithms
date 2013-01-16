#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n, m;
	fscanf( stdin, "%d%d", &n, &m );
	vector< int > graph[ n + 1 ];
	int i, u, v, count = 0;

	for ( i = 0; i < m; ++i ) {
		fscanf( stdin, "%d%d", &u, &v );
		graph[ u ].push_back( v );
		graph[ v ].push_back( u );
	}
	int found = 0;
	bool visited[ n + 1 ];
	for ( i = 0; i <= n; ++i ) {
		visited[ i ] = false;
	}
	while ( m > 0 ) {
		for ( i = 1; i <= n; ++i ) {
			if ( graph[ i ].size() == 0 ) {
				continue;
			}
			else {
				if ( graph[ i ].size() == 1 ) {
					int p = graph[ i ][ 0 ];
					if ( !visited[ i ] ) {
						graph[ i ].pop_back();
						for ( int j = 0; j <= graph[ p ].size(); ++j ) {
							int k = graph[ p ][ j ];
							if ( k == i ) {
								graph[ p ][ j ] = graph[ p ].back();
								graph[ p ].pop_back();
							}
						}
						visited[ p ] = true;
						found = 1;
					}
				}
			}
		}
		if ( !found ) {
			break;
		}
		for ( i = 0; i <= n; ++i ) {
			visited[ i ] = false;
		}
		found = 0;
		++count;
	}
	fprintf( stdout, "%d\n", count );
}
