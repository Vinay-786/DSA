#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionsort(int a[], int n)
{
	int i, j;
	for(i = 0; i<n-1; i++)
	{
		int min = i;
		for(j = i+1; j < n; j++)
		{
			if(a[j] < a[min])
				min = j;
		}
		swap(&a[i], &a[min]);
	}
}


void main()
{
	int a[100];
	printf("Enter the size of the array: ");
	int n; scanf("%d", &n);
	printf("Enter the elements in the array: ");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	selectionsort(a, n);

	for(int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}

