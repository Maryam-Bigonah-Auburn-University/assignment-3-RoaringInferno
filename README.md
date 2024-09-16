[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/1d_xgqq8)
[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/RIWo-ioc)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=12317125&assignment_repo_type=AssignmentRepo)
# assignment_3


## Assignment 3 Chapter 5

### Exercise 1 (20 points)

An array can be used to store large integers one digit at a time. For example,
the integer 1234 could be stored in the array a by setting a[0] to 1, a[1] to 2,
a[2] to 3, and a[3] to 4. However, for this exercise you might find it more useful
to store the digits backward.


In this exercise you will write a program that reads in two positive integers that
are 20 or fewer digits in length and then outputs the sum of the two numbers. Your
program will read the digits as values of type char so that the number 1234 is read
as the four characters '1','2','3', and '4'. After they are read into the program,
the characters should be converted to type int and read into a partially filled array.
Your program should perform the addition by implementing the usual paper-and-pencil
addition algorithm. The result of the addition is stored in an array of size 20 and
the result is then written to the screen.

### Exercise 2 (20 points)

Write a program that assigns passengers seats in an airplane. Assume the airplane
has 7 rows of 4 seats:

1ABCD

2ABCD

3ABCD

4ABCD

5ABCD

6ABCD

7ABCD

Your program should display the available seats in the airplane and ask the user to enter
a row number and seat letter. If that seat is open, tell the user what their seat number
is and update the available seats by placing an 'X' in the occupied seat. If the seat is
already occupied, inform the user with relevant output.

Your program should allow the user to continue booking seats until they quit the program
or there are no empty seats left.

### Exercise 3 (20 points)

Write a program that reads in an array of integers. You may assume that there
are fewer than 50 entries in the array.

Your program should sort the array in descending order and print out each
unique value along with how many times it appears in the array in two-column
format. Each column should be of width 10 and left justified.
