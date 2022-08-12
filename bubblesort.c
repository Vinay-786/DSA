#include <stdio.h>

void bubble_sort(int a[100], int n)
{
	int temp;
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void input(int a[100], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}

void traverse(int a[100], int *n)
{
	int i;
	for(i = 0; i < *n; i++)
	{
		printf("%d\t", a[i]);
	}
}
	

void main()
{
	int n, a[100];
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements of the array: \n");
	
	input(a, n);	

	bubble_sort(a, n);
	
	traverse(a, &n);

}


