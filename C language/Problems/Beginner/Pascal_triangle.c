#include <stdio.h>
int count(int n, int r);
int main()
{
    int rows;
    scanf("%d", &rows);
    for (int n = 0; n < rows; n++){
        for(int i = 1; i < rows-n; i++)
            printf(" ");
        for (int r = 0; r <= n; r++)
        {
            (r == n)?printf("%d",count(n,r)):printf("%d ",count(n,r));
        }
        printf("\n");
    }
    return 0;
}
int count(int n, int r)
{
    int num = 1, denum = 1;
    for (int i = 0; i < r; i++)
    {
        num *= (n - i);
    }
    while (r != 0)
    {
        denum *= r;
        r--;
    }
    return (num / denum);
}