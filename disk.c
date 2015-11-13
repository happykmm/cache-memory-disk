#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define looptimes 10000

int main() {
	int i, value = 1024;
	FILE* fp = fopen("testfile", "wb");
	for (i=0; i<looptimes; i++)
		fwrite(&value, 4, 1, fp);
	fclose(fp);


	clock_t start = clock(), diff;
	for (i=0; i<looptimes-1; i++) {
		fp = fopen("testfile", "rb");
		fread(&value, 4, 1, fp);
		fclose(fp);
	}
	diff = clock() - start;
	double nsec = 1.0 * diff * 1000 / CLOCKS_PER_SEC * 1000 * 1000;
	printf("%d times in %d clocks \n", looptimes, diff);
	printf("%lfns", nsec/looptimes);

}