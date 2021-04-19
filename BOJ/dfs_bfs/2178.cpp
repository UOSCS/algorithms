#include <iostream>
#include <queue>

using namespace std;

bool is_visited[100][100];
int N, M, arr[100][100], count[100][100];
int dn[4] = {-1, 1, 0, 0}, dm[4] = {0, 0, -1, 1};

void bfs(int start_n, int start_m)
{
    queue<pair<int, int>> q;

    q.push(make_pair(start_n, start_m));
    is_visited[start_n][start_m] = true;
    count[start_n][start_m] = 1;
    while(!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        if(node.first == N - 1 && node.second == M - 1)
            return;
        for(int i = 0; i < 4; i++)
        {
            int new_n = node.first + dn[i], new_m = node.second + dm[i];
            if((new_n >= 0 && new_n < N && new_m >= 0 && new_m < M) &&
               arr[new_n][new_m] && !is_visited[new_n][new_m])
            {
                is_visited[new_n][new_m] = true;
                count[new_n][new_m] = count[node.first][node.second] + 1;
                q.push(make_pair(new_n, new_m));
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d", &arr[i][j]);

    bfs(0, 0);

    cout << count[N - 1][M - 1] << '\n';

    return 0;
}