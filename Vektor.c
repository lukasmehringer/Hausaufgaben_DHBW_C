#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 5;

	int* vec; // zeigt auf zusammenhängende adress
	vec = (int*)malloc( size * sizeof(int));


	printf("Values of vec:\n");
	for (int i = 0; i < size; i++)
	{
		printf("value %d = %d\n", i, vec[i]);
	}

	printf("adress of vec in hex: \n");
	for (int i = 0; i < size; i++)
	{
		printf("mem(ptr[i]) = %p\n", &vec[i]);
	}

	printf("adress of vec in dec: \n");
	for (int i = 0; i < size; i++)
	{
		printf("mem(ptr[i]) = %d\n", &vec[i]);
	}

	return 0;
}