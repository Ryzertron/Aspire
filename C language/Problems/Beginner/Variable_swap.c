/*This code interchanges the values in two integer variables without using
a temporary third variable*/
#include <stdio.h>
int main()
{
    int a = 10, b = 20;
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d\nb = %d", a, b);

    return 0;
}