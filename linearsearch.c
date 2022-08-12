#include <stdio.h>

int main(void)
{
	int size, r, i;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int arr[size];
	printf("Enter the elements in the array:\n");
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter the number to search: ");
	scanf("%d", &r);
	
	for(i = 0; i < 10; i++)
	{
		if(arr[i] == r)
		{
			printf("Found the number: index[%d]\n", i);
			break;
		} 
	}
	
}
