#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int arr[25][25], is_visited[25][25];

void dfs(int x, int y, int &count)
{
    is_visited[x][y] = true;
    count++;
    for(int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i], new_y = y + dy[i];
        if((new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) && 
            arr[new_x][new_y] && !is_visited[new_x][new_y])
            dfs(new_x, new_y, count);
    }
}

int main(void)
{
    vector<int> result;

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%1d", &arr[i][j]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(arr[i][j] && !is_visited[i][j])
            {
                int count = 0;
                dfs(i, j, count);
                result.push_back(count);
            }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';

    return 0;
}