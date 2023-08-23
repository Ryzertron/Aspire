#include <stdio.h>
void MergeSort(int arr[], int First, int Last);
void Merge(int arr[], int First, int Middle, int Last);
int main(){
    int arr[] = {96, 34, 7, 78, 56, 78};
    int size = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,size-1);
    for(int i = 0; i < size; i++)
        printf("%d ",arr[i]);
    return 0;
}

void MergeSort(int arr[], int First, int Last){
    if(First < Last){
        int Middle = First + (Last -  First)/2;
        MergeSort(arr , First, Middle);
        MergeSort(arr, Middle+1, Last);
        Merge(arr, First, Middle, Last);
    }
}

void Merge(int arr[], int First, int Middle, int Last){
    int size1 = Middle - First + 1;
    int size2 = Last - Middle;
    int i, j, k;
    int L[size1], R[size2];
    for(i = 0; i < size1; i++)
        L[i] = arr[First + i];
    for(j = 0; j < size2; j++)
        R[j] = arr[Middle + j + 1];
    i = 0;
    j = 0;
    k = First;
    while(i < size1 && j < size2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
            k++;
        }else{
            arr[k] = R[j];
            j++;
            k++;
        }   
    }
    while(i < size1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < size2){
        arr[k] = R[j];
        j++;
        k++;
    }
}