#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define looptimes 100000000

int main() {
	int i;
	int k;
	clock_t start = clock(), diff;
	for (i=0; i<looptimes; i++) {
		k = i;
	}
	diff = clock() - start;
	double nsec = 1.0 * diff * 1000 / CLOCKS_PER_SEC * 1000 * 1000;
	printf("%d times in %d clocks \n", looptimes, diff);
	printf("%lfns", nsec/looptimes);

}