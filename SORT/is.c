#include <stdio.h>

void Swap ( int a[], int, int );

int main() {
	int i = 0, j, N = 5, iMin;
	int array[5];

	array[0] = 5;
	array[1] = 4;
	array[2] = 1;
	array[3] = 2;
	array[4] = 6;

	for ( j = 0; j < N; ++j ) {
		iMin = j;

		for ( i = j + 1; i < N; ++i ) {
			iMin = i;
			while ( array[i] < array[i-1] ) {
				Swap( array, i-1, i );
				--i;
			}
			i = iMin;
		}
	}

	return 0;
}

void Swap ( int array[], int i, int j ) {
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
