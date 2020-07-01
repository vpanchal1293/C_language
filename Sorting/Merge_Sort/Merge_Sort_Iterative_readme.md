0 1 2 3 4 5 6

1 st Iteration -> window_size = 1 
0 1 2 3 4 5 6
01 23 45 6
loop 0 => start = 0, mid = 0, end = 1
loop 1 => start = 2, mid = 2, end = 3
loop 2 => start = 4, mid = 4, end = 5

2 nd iteration -> window_size = 2
01 23 45 6
0123 456
loop 0 => start = 0, mid = 1, end = 3
loop 1 => start = 4, mid = 5, end = 6


3 rd iteration -> window_size = 4
0123 456
loop 0 => start = 0, mid = 3, end = 6
0123456



(55) (50) (28) (21) (75) (71) (10) --> window_size = 1

(50 55) (21 28) (71 75) (10) --> window_size = 2

(21 28 50 55 10) (71 75)--> window_size = 4

(10 21 28 50 55 71 75)
