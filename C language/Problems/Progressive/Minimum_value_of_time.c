/*
Anup is training for a marathon that will take place in N days. He needs to run M practice sessions
to prepare for the marathon, and the i-th session requires Time[i] minutes of running. Anup has
decided on some rules for the session:-

    • He will only move to the next session after completing the ongoing session.
    • Session once started will be completed on the same day.
    • He will sequentially complete the sessions.

Anup wants to distribute his training sessions over N days to minimize the maximum time he
runs in a day. Take total minutes in Anup's day as infinity(Sentinel Value). Print the minimum value of the maximum
amount of time he needs to allocate each day to complete all sessions in N days.
[Optional: Use Binary Search for an efficient runtime.]

Example:-
    Input : N = 4
            M = 7
            Time[] = {2,2,3,3,4,4,1}

    Expected Output : 6

*/
//Solution
#include <stdio.h>
int permutable(int time[], int sets, int days, int limit);
int regress_time(int time[], int sets, int days, int sum, int min);
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int time[M], sum = 0, min = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%ld", time + i);
        sum += time[i];
        if (min > time[i] || i == 0)
        {
            min = time[i];
        }
    }
    printf("%d", regress_time(time, M, N, sum, min));
    return 1;
}
int regress_time(int time[], int sets, int days, int Last, int First)
{
    unsigned int ans, Middle;
    //Binary Search used here. Linear Search can also be applied here.
    while (First <= Last)
    {
        Middle = (First + Last) / 2;
        if (permutable(time, sets, days, Middle))
        {
            ans = Middle;
            Last = Middle - 1;
        }
        else
            First = Middle + 1;
    }
    return ans;
}
int permutable(int time[], int sets, int days, int limit)
{
    int i = 0;
    int demand_days = 1;
    unsigned int split_time = 0;
    while (i < sets)
    {
        if (time[i] > limit)
        {
            return 0;
        }
        else if ((split_time + time[i]) <= limit)
        {
            split_time += time[i];
            i++;
        }
        else
        {
            demand_days += 1;
            split_time = 0;
        }
        if (demand_days > days)
        {
            return 0;
        }
    }
    return 1;
}