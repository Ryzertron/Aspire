#include <stdio.h>
int BinarySearch(int arr[],int First,int Last,int key);
int main(){
    int arr[] = {23,67,89,123,469,1080}, key = 469;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d",BinarySearch(arr,0,size-1,key));
    return 1;
}
int BinarySearch(int arr[],int First,int Last,int key){
    while(First<=Last){
        int Middle = First+(Last-First)/2;
        if(arr[Middle] == key)
            return Middle;
        else if(key < arr[Middle])
            Last = Middle - 1;
        else
            First = Middle + 1;
    }
    return -1;
}