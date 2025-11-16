// Template C to x86 call
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

double sdot(float* a, float* b, int n);

extern void asmhello();
int main(int argc, char* argv[]) {
	asmhello();
	int vector_size = pow(2, 30);

	clock_t begin = clock();
	float* a = (float*)malloc(vector_size * sizeof(float));
	float* b = (float*)malloc(vector_size * sizeof(float));
	// sanity check for malloc
	if (a == NULL || b == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		free(a);
		free(b);
		return 1;
	}

	for (int i = 0; i < vector_size; i++) {
		a[i] = (float)(i + 1);
		b[i] = (float)(i + 1);
	}

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	double result = sdot(a, b, vector_size);
	printf("Dot product: %f", result);
	printf("\nTime spent: %f seconds\n", time_spent);
	free(a);
	free(b);

	return 0;
}

// vector dot product
double sdot(float* a, float* b, int n) {
	double dprod = 0;
	for (int i = 0; i < n; i++) {
		dprod += (double)a[i] * (double)b[i];
	}

	return dprod;
}