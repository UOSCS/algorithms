#include <iostream>
#include <queue>

using namespace std;

int width, height, matrix[100][100], current_slice, hour;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool is_visited[100][100];
queue<pair<int, int>> q;

void dfs(int i, int j)
{
    is_visited[i][j] = true;
    q.push({ i, j });

    for(int k = 0; k < 4; k++)
    {
        int next_i = i + di[k], next_j = j + dj[k];

        if((next_i < height && next_i >= 0 && next_j < width && next_j >= 0) &&
           !matrix[next_i][next_j] && !is_visited[next_i][next_j])
            dfs(next_i, next_j);
    }
}

void bfs()
{
    while(!q.empty())
    {
        int current_size = q.size(), melted_slice = 0;

        hour++;

        while(current_size--)
        {
            int i = q.front().first, j = q.front().second;

            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int next_i = i + di[k], next_j = j + dj[k];

                if((next_i < height && next_i >= 0 && next_j < width && next_j >= 0) && 
                   !is_visited[next_i][next_j])
                    if(matrix[next_i][next_j])
                    {
                        melted_slice++;
                        matrix[next_i][next_j] = 0;
                        is_visited[next_i][next_j];
                        q.push({ next_i, next_j });
                        dfs(next_i, next_j);
                    }
            }
        }

        if(current_slice - melted_slice == 0)
            return;
        else
            current_slice -= melted_slice;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> height >> width;
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j])
                current_slice++;
        }

    dfs(0, 0);

    bfs();

    cout << hour << '\n' << current_slice;

    return 0;
}