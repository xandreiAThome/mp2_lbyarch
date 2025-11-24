#include <stdio.h>

extern float dotproduct(int n, float *vectorA, float *vectorB);

int main() {
	int n = 5;
	float vectorA[] = {1.0, 2.0, 3.0, 4.0};
	float vectorB[] = {5.0, 6.0, 7.0, 8.0};
	float sdot = dotproduct(n, vectorA, vectorB);

	printf("sdot = %f\n", sdot);

	return 0;
}