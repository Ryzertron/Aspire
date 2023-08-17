#include <stdio.h>
int main(){
    int arr[] = {7,4,9,2,1,5,8,-1}, n = 8, j, key;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i;
        while(j >= 0){
            if(j == 0){
               arr[0] = key;
               break;
            }
            else if(key >= arr[j-1]){
                arr[j] = key;
                j--;
                break;
            }
            else if(key < arr[j-1]){
                 arr[j] = arr[j-1];
                 j--;
            }
        }
    
    }

     for(int k = 0; k < n; k++){
        printf("%d ",arr[k]);
    }


    return 0;
}