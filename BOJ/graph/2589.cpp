#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int width, height, ans;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool visited[50][50];
char mat[50][50];

void bfs(int start_i, int start_j)
{
    queue<pair<int, int>> q;
    int distance = 0;

    visited[start_i][start_j] = true;

    for(int k = 0; k < 4; k++)
    {
        int new_i = start_i + di[k], new_j = start_j + dj[k];

        if((new_i < height && new_i >= 0 && new_j < width && new_j >= 0) &&
           mat[new_i][new_j] == 'L' && !visited[new_i][new_j])
        {
            visited[new_i][new_j] = true;
            q.push({ new_i, new_j });
        }
    }

    while(!q.empty())
    {
        int current_queue_size = q.size();

        distance++;

        while(current_queue_size--)
        {
            int current_i, current_j;
            pair<int, int> current_node;

            current_node = q.front(), q.pop();

            current_i = current_node.first, current_j = current_node.second;

            for(int k = 0; k < 4; k++)
            {
                int new_i = current_i + di[k], new_j = current_j + dj[k];

                if((new_i < height && new_i >= 0 && new_j < width && new_j >= 0) &&
                   mat[new_i][new_j] == 'L' && !visited[new_i][new_j])
                {
                    visited[new_i][new_j] = true;
                    q.push({ new_i, new_j });
                }
            }
        }
    }

    ans = max(distance, ans);
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> height >> width;
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            cin >> mat[i][j];

    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            if(mat[i][j] == 'L')
            {
                memset(visited, false, sizeof(visited));
                bfs(i, j);
            }

    cout << ans;

    return 0;
}