#include <stdio.h>

int find_min(int n)
{
    int first, last;

    if (n == 0)
        return 0;
    else
    {
        if (n & 1)
            first = last = n / 2;
        else
        {
            first = n / 2 - 1;
            last = n / 2;
        }
        return ((n + 1) + find_min(first) + find_min(last));
    }
}

int main()
{
    int T, M, N, min, max;

    scanf("%d", &T);

    while (T--)
    {
        scanf("%d %d", &N, &M);

        min = find_min(N);
        max = N * (N + 3) / 2;

        if (M < min)
            printf("-1\n");
        else if (M > max)
            printf("%d\n", (M - max));
        else
            printf("0\n");
    }

    return 0;
}