#include <stdio.h>
void mergeSort(int array[],int l,int r);
void print_array(int array[] , int len);
void merge(int array[], int l ,int m,int r);
int main(void)
{
    int array[] = {64, 25, 12, 22, 11}; 
    int len = sizeof(array)/sizeof(array[0]);
    printf("Before Sorting\n");
    print_array(array , len);
    
    mergeSort(array , 0 , len-1);
    
    printf("Aftre Sorting\n");
    print_array(array , len);
}

void mergeSort(int array[],int l,int r)
{
    int mid = 0;
    if(l<r)
    {
        //mid = (l+r)/2 , to avoid overflow condition
        mid = l+(r-l)/2;
        
        //sort first half
        mergeSort(array, l, mid);
        
        //sort second half
        mergeSort(array, mid+1 , r);
        
        //merge first and second half
        merge(array, l, mid, r);
    }
}


void merge(int array[], int l ,int m,int r)
{
    //merge two array[l to m] and array[m+1 to r]
    int n1 = 0, n2 = 0, i = 0, j = 0, k = 0;
    
    //calculate len of first array
    n1 = m - l + 1;
    
    //calculate len of second array
    n2 = r - (m + 1) + 1;
    
    //create two temp array with len of n1 and n2
    int L[n1], R[n2];
    
    //copy array[l to m] data to first temp array
    for(i = 0; i < n1; i++)
    L[i] = array[l+i];
    
    //copy array[m+1 to r] data to second temp array
    for(j = 0; j < n2; j++)
    R[j] = array[m+1+j];
    
    
    //copy data from both temp array to original array with Sorting
    i = 0;  //start from first temp array first element
    j = 0;  //start from second temp array first element
    k = l;  //Start copying data to original array l'th location 
    while((i < n1) && (j < n2))
    {
        //compare both array element and copy
        if(L[i] <= R[j])
        {
            array[k++] = L[i++];
        }
        else
        {
            array[k++] = R[j++];
        }
    }
    
    //copy remaining first temp array data if available
    while(i < n1)
    {
        array[k++] = L[i++];
    }
    
    while(j < n2)
    {
        array[k++] = R[j++];
    }
}

void print_array(int array[] , int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    printf("%d ",array[i]);
    printf("\n");
}