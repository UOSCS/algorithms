#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N, stats[20][20], is_selected[20], min = INT_MAX;

int get_diff()
{
    int stats_of_selected = 0, stats_of_unselected = 0, selected[10], unselected[10];

    for(int i = 0, sel_count = 0, unsel_count = 0, count = 0; i < N; i++)
        if(is_selected[i])
            selected[sel_count++] = i;
        else
            unselected[unsel_count++] = i;

    for(int i = 0; i < N / 2; i++)
        for(int j = i + 1; j < N / 2; j++)
        {
            stats_of_selected += stats[selected[i]][selected[j]] + stats[selected[j]][selected[i]];
            stats_of_unselected += stats[unselected[i]][unselected[j]] + stats[unselected[j]][unselected[i]];
        }

    return abs(stats_of_selected - stats_of_unselected);
}

void dfs(int start, int depth)
{
    for(int i = start, diff; i < N; i++)
    {
        is_selected[i] = 1;
        if(depth == N / 2 - 1)
        {
            if(min > (diff = get_diff()))
                min = diff;
        }
        else
            dfs(i + 1, depth + 1);
        is_selected[i] = 0;
    }
}

int main(void)
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", stats[i] + j);

    dfs(0, 0);

    printf("%d\n", min);

    return 0;
}