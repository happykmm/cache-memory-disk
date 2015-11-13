#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arraysize 1000000
#define looptimes 1000

int main() {
	int repeat, index = 0;
	int* array = (int *)malloc(sizeof(int)*arraysize);
	clock_t start = clock(), diff;
	for (repeat=0; repeat<looptimes; repeat++) {
		for (index=0; index<arraysize; index+=16) {
			array[index] = index;
		}
	}
	diff = clock() - start;
	int loops = index / 16 * looptimes;
	double nsec = 1.0 * diff * 1000 / CLOCKS_PER_SEC * 1000 * 1000;
	printf("%d times in %d clocks \n", loops, diff);
	printf("%lfns", nsec/loops);
}


/*

L3 cache size: 3072KB
block size: 64Byte   ->  16 int
blocks: 49152

49152 * 16 = 78,6432

*/