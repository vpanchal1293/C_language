#include <stdio.h>
void Insertion_sort(int array[],int len);
void Insertion_sort_recursion(int array[],int len);
void print_array(int array[] , int len);
int main(void)
{
    int array[] = {64, 25, 12, 22, 11}, len = 5; 
    
    printf("Before Sorting\n");
    print_array(array , len);
    Insertion_sort(array , len);
    printf("Aftre Sorting\n");
    
    print_array(array , len);
    
    
    int array_2[] = {64, 25, 12, 22, 11}; 
    printf("Before Sorting\n");
    print_array(array_2 , len);
    Insertion_sort_recursion(array_2 , len);
    printf("Aftre Sorting\n");
    print_array(array_2 , len);
    return 0;
}

void Insertion_sort(int array[],int len)
{
    int i = 0, j = 0, key = 0;
    for(i = 1; i < len; i++)
    {
        key = array[i];
        j = i - 1;
        while(j>=0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void Insertion_sort_recursion(int array[],int len)
{
    int i = 0, key = 0, j = 0;
    
    if(len == 1)
    {
        return;
    }
    
    Insertion_sort_recursion(array,len-1);
    
    key = array[len - 1];
    j = len - 2;
    while(j>=0 && array[j] > key)
    {
        array[j+1] = array[j];
        j--;
    }
    array[j+1] = key;
    
}


void print_array(int array[] , int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    printf("%d ",array[i]);
    printf("\n");
}
