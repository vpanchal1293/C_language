#include <stdio.h>
void selection_sort(int array[],int len);
void selection_sort_recursion(int array[],int len);
void print_array(int array[] , int len);
int main(void)
{
    int array[] = {64, 25, 12, 22, 11}, len = 5; 
    
    printf("Before Sorting\n");
    print_array(array , len);
    selection_sort(array , len);
    printf("Aftre Sorting\n");
    
    print_array(array , len);
    
    
    int array_2[] = {64, 25, 12, 22, 11}; 
    printf("Before Sorting\n");
    print_array(array_2 , len);
    selection_sort_recursion(array_2 , len);
    printf("Aftre Sorting\n");
    print_array(array_2 , len);
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
            array[min_index] = array[i] + array[min_index] - (array[i] = array[min_index]);
        }
    }
}

void selection_sort_recursion(int array[],int len)
{
    if(len == 1)
    {
        //if only one element left means full array is sorted 
        return;
    }
    int i = 0, min_index = 0;
        //Take min_index from 0 to len-1
        min_index = 0;
        for(i = 1; i < len; i++)
        // Find min element form unsroted array (min_index+1 to last element of array)
        if(array[min_index] > array[i])
        {
            //Update min_index to index of smallest element of unsorted array
            min_index = i;
        }
        
        if(min_index != 0)
        {
            // if no Update in min_index then swap the element
            array[min_index] = array[0] + array[min_index] - (array[0] = array[min_index]);
        }
        selection_sort_recursion(array+1 ,len-1);
}


void print_array(int array[] , int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    printf("%d ",array[i]);
    printf("\n");
}
