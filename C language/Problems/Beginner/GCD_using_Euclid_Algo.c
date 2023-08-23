//Program to find GCD using the Euclidean Basic Algorithm.
#include <stdio.h>
int GCD(int low, int high);
int main(){
    int a = 36, b = 12;
    int result = GCD(b,a);
    printf("%d",result);

    return 1;
}
int GCD(int low, int high){
    if(!low)
        return high;
    return GCD(high%low, low);
}