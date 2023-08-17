#include <stdio.h>
int main(){
    int key,pos,head = 0,arr[5] = {3,6,2,34,78},size = 5;

    while(head<size-1){
        for(int j = head; j < size; j++){
            if(j == head || arr[j]<key){
                key = arr[j];
                pos = j;
            }
        }
        arr[pos] = arr[head];
        arr[head] = key;
        head++;
    }
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}