#include <stdio.h>

void Shift_Array(int arr[], int n, int shift) ;
void reverse_array(int a[],int n);
void print_array(int array[] , int len);

int main(void)
{
    int array[] = {1,2,3,4,5,6,7,8}; 
    int len = sizeof(array)/sizeof(array[0]);
    
    printf("Before Sorting\n");
    print_array(array , len);
    
    Shift_Array(array , len, 3);
    
    printf("Aftre Sorting\n");
    print_array(array , len);
}

void Shift_Array(int arr[], int n, int shift) 
{
    //[0 1 2.... shift-1] to [shift-1 ... 2 1 0]
    reverse_array(arr, shift);
    
    //[shift .... n] to [n .... shift]
    reverse_array(arr + shift, n - shift);
    
    //[shift-1 .... 2 1 0 ... n ... shift] to
    //[shift ... n ... 0 1 2 .. shift-1]
    reverse_array(arr, n);
     
} 

void reverse_array(int arr[], int n)
{
    int i = 0, j = n - 1;
    for( ; i<j; i++,j--)
        if( arr[i] != arr[j] )
        arr[i] = arr[j] + arr[i] - (arr[j] = arr[i]);
}

void print_array(int array[] , int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    printf("%d ",array[i]);
    printf("\n");
}