/*This program takes an integer as input and
check if it is a palidrome or not
It will will give output as 1 if the integer is a palindrome and an output as 0 when it is not.*/
#include <stdio.h>
int main()
{
    int num, rev = 0, digit, check;
    scanf("%d", &num);
    check = num;
    while (num != 0)
    {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    }
    if (check == rev)
        printf("1");

    else
        printf("0");

    return 0;
}