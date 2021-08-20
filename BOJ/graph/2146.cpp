#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, matrix[100][100];
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool is_visited[100][100];

void dfs(int i, int j, int sequence)
{
    is_visited[i][j] = true;
    matrix[i][j] = sequence;

    for(int k = 0; k < 4; k++)
    {
        int next_i = i + di[k], next_j = j + dj[k];

        if((next_i >= 0 && next_i < N && next_j >= 0 && next_j < N) &&
           matrix[next_i][next_j] && !is_visited[next_i][next_j])
            dfs(next_i, next_j, sequence);
    }
}

int bfs(int sequence)
{
    queue<pair<int, int>> q;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(matrix[i][j] == sequence)
            {
                q.push({ i, j });
                is_visited[i][j] = true;
            }

    int length = 0;

    while(!q.empty())
    {
        int current_size = q.size();

        while(current_size--)
        {
            pair<int, int> current = q.front();
            int i = current.first, j = current.second;

            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int next_i = i + di[k], next_j = j + dj[k];

                if(next_i >= 0 && next_i < N && next_j >= 0 && next_j < N)
                {
                    if(matrix[next_i][next_j] && matrix[next_i][next_j] != sequence)
                        return length;
                    else if(!is_visited[next_i][next_j])
                    {
                        q.push({ next_i, next_j });
                        is_visited[next_i][next_j] = true;
                    }
                }
            }
        }

        length++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> matrix[i][j];

    int sequence_of_island = 1;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(matrix[i][j] && !is_visited[i][j])
            {
                dfs(i, j, sequence_of_island);
                sequence_of_island++;
            }

    int shortest_bridge = 200;

    for(int i = 1; i < sequence_of_island; i++)
    {
        memset(is_visited, false, sizeof(is_visited));

        shortest_bridge = min(shortest_bridge, bfs(i));
    }

    cout << shortest_bridge;

    return 0;
}