/*
In a distant land, an ancient scroll contains a sequence of distinct numbers. The scroll’s magical
power is said to be activated only when the sequence is rotated at some point. The sequence of
numbers is sorted in ascending order and then rotated at an unknown point, making it difficult to
navigate and find specific elements.
    Given a rotated sequence of distinct elements and the secret number you seek, your task is to
write a program that finds the secret number’s position within the sequence(starting with zero) by
doing minimum number of comparisons (on an average). If the secret number is not present, your
program should print -1.

Example :-
    Input : n = 9
            arr = {5, 6, 7, 8, 9, 10, 1, 2, 3}
            key = 8
    Expected Output : 3
*/
//SOLUTION (Using Binary Search)
#include <stdio.h>
void Decrypt(int sequence[], int len, int key);
int main()
{
    int n, key;
    scanf("%d", &n);
    int sequence[n];
    for (int i = 0; i < n; i++)
        scanf("%d", sequence + i);
    scanf("%d", &key);
    Decrypt(sequence, n, key);

    return 1;
}
void Decrypt(int sequence[], int len, int key)
{
    int First = 0, Last = len - 1, Middle, result;
    while (First <= Last)
    {
        Middle = (First + Last) / 2;
        if (key == sequence[Middle])
        {
            result = Middle;
            break;
        }
        else if (First == Last)
        {
            result = -1;
            break;
        }
        else if (key >= sequence[First])
        {
            if (sequence[Middle] >= sequence[First] && key > sequence[Middle])
                First = Middle + 1;
            else
                Last = Middle - 1;
        }
        else
        {
            if (sequence[Middle] <= sequence[First] && key < sequence[Middle])
                Last = Middle - 1;

            else
                First = Middle + 1;
        }
    }

    printf("%d", result);
}