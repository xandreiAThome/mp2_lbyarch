// Template C to x86 call
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

float sdot(float* a, float* b, int n);

extern float sdot_asm(float *a, float *b, int n);
int main(int argc, char* argv[]) {
	printf("Running program...\n");

	int vector_size = pow(2, 30);
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

	clock_t begin = clock();
	float asm_result = sdot_asm(a, b, vector_size);
	clock_t end = clock();

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Dot product from asm kernel: %f\n", asm_result);
	printf("Time spent: %f seconds\n", time_spent);

	begin = clock();
	float result = sdot(a, b, vector_size);
	end = clock();

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Dot product from C kernel: %f\n", result);
	printf("Time spent: %f seconds\n", time_spent);

	if(result == asm_result) {
		printf("asm kernel results match with the C kernel!\n");
	} else {
		printf("Results do not match!\n");
	}

	free(a);
	free(b);

	return 0;
}

// vector dot product
float sdot(float* a, float* b, int n) {
	float dprod = 0;
	for (int i = 0; i < n; i++) {
		dprod += a[i] * b[i];
	}

	return dprod;
}