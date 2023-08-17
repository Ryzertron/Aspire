/*This code checks whether the given integer is a prime number.*/
#include <stdio.h>
int main()
{
    int num = 37;
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
        {
            printf("%d is Not a Prime",num);
            return 0;
        }
    }
    printf("%d is a PRIME!", num);
    return 0;
}