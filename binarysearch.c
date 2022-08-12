#include <stdio.h>

int binary_search(int a[], int n, int element)
{
	int low = 0, high = n-1;
	while(low <= high)
	{
		int mid = (low+high)/2;
		if(element == a[mid])
			return mid;
		else if(element < a[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}

void main()
{
	int a[50];
	printf("Enter the size of the array: ");
	int n; scanf("%d", &n);
	printf("Enter the elements in the array(sorted):\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter a number: ");
	int x; scanf("%d", &x);
	int index = binary_search(a, n, x);
	if(index != -1)
	{
		printf("number %d is at index %d\n", x, index);
	}
	else
		printf("number %d not found\n", x);
}

