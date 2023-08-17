/*This is a code to check whether the given integer is a Perfect Number or not.
It gives 1 if the number is Perfect and 0 if not perfect.*/
#include <stdio.h>
int main(){
    int input,output = 0;
    scanf("%d",&input);
    for(int i = 1; i <= input/2; i++){
        if(input % i == 0){
            output += i;
        }
    }
    if(output == input)
        printf("1");
    else
        printf("0");
    return 0;
}