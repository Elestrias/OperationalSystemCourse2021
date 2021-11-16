#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int columnLen = 3;
    int rowsLen = 5;

    int E[columnLen], A[columnLen], C[rowsLen][columnLen], R[rowsLen][columnLen];
    for(int i = 0; i < columnLen; ++i)
    {
        scanf("%d", &E[i]);
    }
    for(int i = 0; i < columnLen; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < rowsLen; ++i)
    {
        for(int j = 0; j < columnLen; ++j)
        {
            scanf("%d", &C[i][j]);
        }
    }
    for(int i = 0; i < rowsLen; ++i)
    {
        for(int j = 0; j < columnLen; ++j)
        {
            scanf("%d", &R[i][j]);
        }
    }

    int unUse[rowsLen];

    for(int i = 0; i < rowsLen; ++i)
    {
        unUse[i] = 1;
    }

    for(int i = 0; i < rowsLen; ++i)
    {
        int flag = 1;
        for(int j = 0; j < rowsLen; ++j)
        {
            if (unUse[j])
            {
                for(int t = 0; t < columnLen; ++t)
                {
                    if (A[t] < R[j][t])
                    {
                        goto skip;
                    }
                }
                flag = 0;
                unUse[j] = 0;
                for(int k = 0; k < columnLen; ++k)
                {
                    A[k] += C[i][k];
                }
            }
            skip:;
        }

        int count = 0;
        for(int j = 0; j < rowsLen; ++j)
        {
            count += unUse[j];
        }

        if (count == 0)
        {
            break;
        }
        if (flag == 1)
        {
            printf("Deadlock detected: %d proccesses\n", count);
            return 0;
        }
    }
    printf("No deadlock is detected\n");
    return 0;
}