#include <stdio.h>

int a, b, u, v, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main()
{
    int n;
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix: \n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    visited[i] = 1;
    printf("\n");
    while (ne < n)
    {
        for (int i = 1, min = 999; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\n Edge %d:(%d %d), cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        printf("\n Minimum cost = %d", mincost);
    }
}
