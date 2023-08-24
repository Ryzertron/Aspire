/*
Consider you have an array of ’n’ distinct integers. You aim to
find the ’special min’ elements from this array. A ’special min’ element is one that is smaller than
all of its neighboring elements within the array. Each element within the array has neighbors, which
consist of the element to its immediate left and the one to its immediate right. Notably, the first
and last elements have only one neighbor, while all others possess two neighbors. After locating the
’special min’ elements within the array, store them chronologically in another array called ’special’
and remove all ’special min’ elements from the original array. Repeat this process until the array is
empty (Note:- if the array contains only 1 element, that element itself is the ’special min’ element).
Design a program to display the elements in the ’special’ array. For example: Given the array
{4, 7, 8, 1, 5, 9}, the first set of ’special min’ elements consists of 4 and 1. After removing these
elements, the array becomes {7, 8, 5, 9}. The next set of ’special min’ elements comprises 7 and 5.
This leads to a remaining array of {8, 9}. The subsequent ’special min’ element is 8, reducing the
array to {9}. Finally, the last ’special min’ element is 9, resulting in an empty array. As a result,
the ’special’ array contains the following elements in sequence: 4, 1, 7, 5, 8, 9.
*/
#include <stdio.h>
void Delete(int arr[], int index, int* size);
void SpecialGenerator(int arr[], int size, int special[],int head);
int main(){
    int size;
    scanf("%d",&size);
    int arr[size],special[size];
    for(int i = 0; i < size; i++)
        scanf("%d",arr+i);
    SpecialGenerator(arr,size,special,0);
    for(int i = 0; i < size; i++)
        printf("%d ",special[i]);
    return 1;
}
void SpecialGenerator(int arr[], int size, int special[],int head){
    int i = 0;
    while(i < size){
        if(size == 1){
            special[head] = arr[0];
            return;
        }
        else if(i == 0){
            if(arr[0]<arr[1]){
                special[head] = arr[0];
                head++;
                Delete(arr,0,&size);
                if(i >= size - 1)
                    i = 0;
                else
                    i++;
            }
            else
                i++;
        }
        else if(i == size-1){
            if(arr[i]<arr[i-1]){
                special[head] = arr[i];
                head++;
                Delete(arr,i,&size);
            }
            i = 0;
        }
        else{
            if(arr[i]<arr[i-1] &&  arr[i]<arr[i+1]){
                special[head] = arr[i];
                head++;
                Delete(arr,i,&size);
                if(i >= size - 1)
                    i = 0;
                else
                    i++;
            }
            else
                i++;
        }
    }
}
void Delete(int arr[], int index, int* size){
    for(int i = index; i < *size - 1; i++)
        arr[i] = arr[i+1];
    *size = *size - 1;
}