Selection sort
Select the minimum element from array and place it to proper place
So array wil be devided in to two part sorted array and unsorted array



Sorted sublist			Unsorted sublist		Least element in unsorted list
( )				(11, 25, 12, 22, 64)		11
(11)				(25, 12, 22, 64)		12
(11, 12)			(25, 22, 64)			22
(11, 12, 22)			(25, 64)			25
(11, 12, 22, 25)		(64)				64
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
