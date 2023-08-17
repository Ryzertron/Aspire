/*This code accepts an integer and prints the factorial of that number.*/
#include <stdio.h>
int main()
{
    int num, ans = 1;
    scanf("%d",&num);
    while (num != 0)
    {
        ans *= num;
        num--;
    }
    printf("%d", ans);

    return 0;
}