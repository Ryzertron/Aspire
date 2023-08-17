/*
Given an ascending sequence, denoted by an array ’A’, its size ‘n’ and an integer ’k’, the objective is
to determine the k-th missing contiguous element (k-th element in the sequence of missing elements)
in this sequence. If the k-th missing element is not there for the sequence, the program should
output -1.[Hint: Use Binary Search to make the process efficient].

Example :-
    Input:  n = 6
            A = {1,2,3,6,8,10}
            k = 3

    Expected Output : 7
*/

//SOLUTION
#include <stdio.h>
void FindMissing(int arr[], int n, int k);
int main()
{
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    scanf("%d", &k);
    FindMissing(arr, n, k);

    return 1;
}

void FindMissing(int arr[], int n, int k)
{
    int First = 0, Middle, Last = n - 1, missing, ans;
    // total missing elements till an element = (element in the array) - (element's position index + 1)
    if ((arr[Last] - n) < k){
            printf("-1");
            return;
        }
    while (First <= Last){
        
        Middle = (First + Last) / 2;
        missing = arr[Middle] - Middle - 1;

        if (missing == k){
            if (Middle > 0 && (arr[Middle - 1] - Middle - 1) == k){
                
                Last = Middle - 1;
                continue;
            }
            ans = arr[Middle] - 1;
            break;
        }
        else if (First == Last){
            if (missing < k){
                ans = arr[Middle] + (k - missing);
                break;
            }else{
                ans = arr[Middle] - (missing - k + 1);
                break;
            }
        }
        else if (missing > k){
            Last = Middle;
        }else{
            First = Middle + 1;
        }
    }
    printf("%d", ans);
}