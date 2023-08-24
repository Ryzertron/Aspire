#include <stdio.h>
int BinarySearchRecursive(int arr[],int First,int Last,int key);
int main(){
    int arr[] = {23,67,89,123,469,1080}, key = 469;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d",BinarySearchRecursive(arr,0,size-1,key));
    return 1;
}

int BinarySearchRecursive(int arr[], int First, int Last, int key){
    int Middle = First + (Last - First)/2;
    if(First>Last)
        return -1;
    else if(arr[Middle] == key)
        return Middle;
    else if(key<arr[Middle])
        return BinarySearchRecursive(arr, First, Middle - 1, key);
    else
        return BinarySearchRecursive(arr, Middle + 1, Last, key);
    
}