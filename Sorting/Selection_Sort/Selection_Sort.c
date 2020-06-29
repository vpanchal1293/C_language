Selection sort
Select the minimum element from array and place it to proper place
So array wil be devided in to two part sorted array and unsorted array



Sorted sublist			Unsorted sublist		Least element in unsorted list
( )						(11, 25, 12, 22, 64)	11
(11)					(25, 12, 22, 64)		12
(11, 12)				(25, 22, 64)			22
(11, 12, 22)			(25, 64)				25
(11, 12, 22, 25)		(64)					64
(11, 12, 22, 25, 64)	( )	


0 1 2 3 4

min_index = 0
1 2 3 4

min_index = 1
2 3 4

min_index = 2
3 4

min_index = 3
4

Outer_loop = 0 to 3
	min_index = Outer_loop
	Inner Loop = Outer_loop+1 to 4
		compare min_index element with Inner Loop element
		Update min_index accordingly

#include <stdio.h>
void selection_sort(int array[],int len);

int main()
{
    printf("Hello World");
    int array[] = {64, 25, 12, 22, 11}, len = 5; 
    print_array(array , len);
    selection_sort(array , len);
    //selectionSort(array , len);
    print_array(array , len);
    return 0;
}

void selection_sort(int array[],int len)
{
    int i = 0, j = 0, min_index = 0;
    for(i = 0; i < len-1; i++)
    {
        //Take min_index from 0 to len-1
        min_index = i;
        for(j = i+1; j < len; j++)
        // Find min element form unsroted array (min_index+1 to last element of array)
        if(array[min_index] > array[j])
        {
            //Update min_index to index of smallest element of unsorted array
            min_index = j;
        }
        
        
        if(min_index != i)
        {
            // if no Update in min_index then swap the element
            array[min_index] = array[j] + array[min_index] - (array[j] = array[min_index]);
        }
        
    }
}

print_array(int array[] , int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    printf("%d ",array[i]);
    printf("\n");
}
