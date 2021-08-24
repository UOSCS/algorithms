#include <iostream>
#include <queue>

using namespace std;

int N, M, matrix[100][100], init_count;
int dn[4] = {-1, 0, 1, 0}, dm[4] = {0, 1, 0, -1};
bool visited[100][100];
queue<pair<int, int>> q;

void dfs(int n, int m)
{
    q.push({ n, m });
    visited[n][m] = true;

    for(int i = 0; i < 4; i++)
    {
        int next_n = n + dn[i], next_m = m + dm[i];

        if((next_n >= 0 && next_n < N && next_m >= 0 && next_m < M) && 
           !matrix[next_n][next_m] && !visited[next_n][next_m])
            dfs(next_n, next_m);
    }
}

int bfs()
{
    int time = 0;

    while(!q.empty())
    {
        int current_size = q.size(), melted_count = 0;

        time++;

        while(current_size--)
        {
            int n = q.front().first, m = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int next_n = n + dn[i], next_m = m + dm[i];

                if((next_n >= 0 && next_n < N && next_m >= 0 && next_m < M) && 
                   matrix[next_n][next_m])
                {
                    if(!(--matrix[next_n][next_m]))
                    {
                        melted_count++;
                        dfs(next_n, next_m);
                    }
                }
            }
        }

        if(!(init_count - melted_count))
            return time;
        else
            init_count -= melted_count;
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j])
            {
                matrix[i][j] = 2;
                init_count++;
            }
        }

    dfs(0, 0);

    cout << bfs();

    return 0;
}