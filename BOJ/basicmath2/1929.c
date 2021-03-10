#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
	int M, N;
	bool* PrimeArray;

	scanf("%d %d", &M, &N);

	PrimeArray = malloc(sizeof(bool) * (N + 1));

	memset(PrimeArray, true, N + 1);
	memset(PrimeArray, false, 2);

	for (int i = 2; i * i <= N; i++) 
    {
		if (PrimeArray[i]) 
        {
			for (int j = i * i; j <= N; j += i)
				PrimeArray[j] = false;
		}
	}

	for (int i = M; i <= N; i++) 
    {
		if (PrimeArray[i])
			printf("%d\n", i);
	}

	free(PrimeArray);

	return 0;
}