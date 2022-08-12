#include <stdio.h>

void insertionsort(int a[], int n)
	{
		int i, j, temp, k;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < i; j++)
			{
				if(a[j] > a[i])
				{
					temp = a[j];
					a[j] = a[i];
					
					for(k = i; k > j; k--)
					{
						a[k] = a[k-1];
					}
					a[k+1] = temp;
				}
			}
		}
	}

void main()
{
	int n, a[100];
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements of the array: \n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	insertionsort(a, n);
	
	for(int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}

}
