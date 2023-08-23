#include <stdio.h>
void QuickSort(int arr[],int target, int Last);
int main(){
    int arr[] = {3,87,45,23,65};
    int size = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,size-1);
    for(int i = 0; i < size; i++)
        printf("%d ",arr[i]);
    return 1;
}

void QuickSort(int arr[],int First, int Last){
    int temp,pivot = Last, target = First;
    if(pivot <= target)
        return;
    while(target != pivot){
        if(arr[target]>=arr[pivot]){
            temp = arr[target];
            arr[target] = arr[pivot-1];
            arr[pivot-1] = arr[pivot];
            arr[pivot] = temp;
            pivot--;
        }
        else
            target++;
    }
    QuickSort(arr,First,pivot-1);
    QuickSort(arr,pivot+1,Last);
}