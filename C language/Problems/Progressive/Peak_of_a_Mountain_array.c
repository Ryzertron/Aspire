/*
You are given an array of ‘n’ integers (both positive and negative) so that the sequence strictly
increases until it reaches a peak, and then strictly decreases. This is known as a mountain array.
You are given such an array. The peak element is an element at position ‘i’ such that:
arr[ i-1 ] < arr[ i ] and arr[ i+1 ] < arr[ i ]
You are asked to use the best known algorithm to minimize the number of comparisons done by
your program on an average to find the peak.

Example :-
    Input : n = 9
            arr = {1,2,3,5,7,8,6,3,1}

    Expected Output : 8
*/
//SOLUTIONS
#include <stdio.h>
void SearchPeak(int arr[], int n);
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    SearchPeak(arr, n);
    return 1;
}
void SearchPeak(int arr[], int n)
{
    int First = 0, Middle, Last = (n - 1);
    while (First <= Last)
    {
        Middle = (First + Last) / 2;
        if (arr[Middle] > arr[Middle-1] && arr[Middle] > arr[Middle+1])
        {
            break;
        }
        else if (arr[Middle] < arr[Middle - 1])
        {
            Last = Middle - 1;
        }
        else
        {
            First = Middle + 1;
        }
    }
    printf("%d", arr[Middle]);
}