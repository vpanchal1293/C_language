#include <stdio.h>
int quick_Sort(int arr[], int size, int num);
void swap(int *p, int *q);
int partition(int arr[], int low, int high);
int printarry(int arr[], int size);
int main (void)
{
	int arr[] = {5, 1, 8, 15, 6, 7,8, 11, 1, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Before Sorting\n");
	printarry(arr,size);
	
	quick_Sort(arr,0,size-1);
	
	printf("After Sorting\n");
	printarry(arr,size);
	
	return 0;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low;
	int j = 0;
	
	for(j = low; j<high; j++)
	{
		if(arr[j] < pivot)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	
	swap(&arr[i],&arr[high]);
	return i;
}

int quick_Sort(int arr[], int low, int high)
{
	int part;
	if (low < high)
	{
		part = partition(arr, low, high);
		quick_Sort(arr, low, part-1);
		quick_Sort(arr, part+1, high);
	}
}

void swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int printarry(int arr[], int size)
{
	int i = 0;
	for(i = 0; i<size; i++)
		printf("%d ",arr[i]);
	printf("\n");
}