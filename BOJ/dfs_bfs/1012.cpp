#include <iostream>
#include <cstring>

using namespace std;

int M, N, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool arr[50][50], is_visited[50][50];

void dfs(int y, int x)
{
    is_visited[y][x] = true;
    for(int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i], new_y = y + dy[i];
        if((new_x >= 0 && new_x < M && new_y >= 0 && new_y < N) && 
            arr[new_y][new_x] && !is_visited[new_y][new_x])
            dfs(new_y, new_x);
    }
}

int main(void)
{
    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int count = 0, K;
        memset(arr, false, sizeof(arr));
        memset(is_visited, false, sizeof(is_visited));
        cin >> M >> N >> K;
        for(int j = 0, tmp1, tmp2; j < K; j++)
        {
            cin >> tmp1 >> tmp2;
            arr[tmp2][tmp1] = true;
        }
        for(int y = 0; y < N; y++)
            for(int x = 0; x < M; x++)
                if(arr[y][x] && !is_visited[y][x])
                {
                    count++;
                    dfs(y, x);
                }
        cout << count << '\n';
    }

    return 0;
}