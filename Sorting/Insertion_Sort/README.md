Insertion Sort
Here array is devided in to two part, Sorted array and Unsortd array

Take first element of Unsortd array as key
compare key with sorted array element in highest to lowest order
- Put key to proper place by sifting element of sorted array.

12, 11, 13, 5, 6

i = 1. 
Key = 11
Since 11 is smaller than 12, move 12 and insert 11 before 12
11, 12, 13, 5, 6

i = 2
Key = 13
13 will remain at its position as all elements in A[0..I-1] are smaller than 13
11, 12, 13, 5, 6

i = 3
Key = 5
5 will move to the beginning and all other elements from 11 to 13 
will move one position ahead of their current position.
5, 11, 12, 13, 6

i = 4
Key = 6
6 will move to position after 5, 
and elements from 11 to 13 will move one position ahead of their current position.
5, 6, 11, 12, 13

--------------------
12, 11, 13, 5, 6
    --
11, 12, 13, 5, 6
        --
11, 12, 13, 5, 6
	   --
5, 11, 12, 13, 6
	      --
--------------------
End of sorting--
5, 6, 11, 12, 13

insertionSort(arr, n) 
    Loop from i = 1 to n-1.
       a) Pick element arr[i] and insert
          it into sorted sequence arr[0..i-1] 
