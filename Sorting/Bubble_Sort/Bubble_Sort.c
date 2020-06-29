#include <stdio.h>
void Bubble_sort(int array[],int len);
void Bubble_sort_recursion(int array[],int len);
void print_array(int array[] , int len);
int main(void)
{
    int array[] = {64, 25, 12, 22, 11}, len = 5; 
    
    printf("Before Sorting\n");
    print_array(array , len);
    Bubble_sort(array , len);
    printf("Aftre Sorting\n");
    
    print_array(array , len);
    
    
    int array_2[] = {64, 25, 12, 22, 11}; 
    printf("Before Sorting\n");
    print_array(array_2 , len);
    Bubble_sort_recursion(array_2 , len);
    printf("Aftre Sorting\n");
    print_array(array_2 , len);
    return 0;
}

void Bubble_sort(int array[],int len)
{
    int i =0, j = 0;
    for(i = 0; i < len-1; i++)
    {
        for(j = 0; j< len-1-i; j++)
        if(array[j] > array[j+1])
        {
            array[j] = array[j+1] + array[j] - (array[j+1] = array[j]);
        }
    }
}

void Bubble_sort_recursion(int array[],int len)
{
    int i = 0;
    
    if(len == 1)
    {
        return;
    }
    
    for(i = 0; i< len-1; i++)
    {
        if(array[i] > array[i+1])
        {
            array[i] = array[i+1] + array[i] - (array[i+1] = array[i]);
        }
    }
    Bubble_sort_recursion(array, len-1);
}


void print_array(int array[] , int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    printf("%d ",array[i]);
    printf("\n");
}
