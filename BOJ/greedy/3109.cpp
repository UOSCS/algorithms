#include <iostream>

using namespace std;

bool is_visited[10000][500], is_valid_path;
int R, C, count, dr[3] = {-1, 0, 1};

void dfs(int current_row, int current_col)
{
    if(current_col == C - 1)
    {
        count++;
        is_valid_path = true;
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            int next_row = current_row + dr[i], next_col = current_col + 1;
            if((next_row >= 0 && next_row < R && next_col < C) &&
               !is_visited[next_row][next_col])
            {
                is_visited[next_row][next_col] = 1;
                dfs(next_row, next_col);
                if(is_valid_path)
                    return;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
        {
            char tmp;
            cin >> tmp;
            is_visited[i][j] = (tmp == 'x' ? true : false);
        }

    for(int i = 0; i < R; i++)
    {
        is_valid_path = false;
        dfs(i, 0);
    }

    cout << count << '\n';

    return 0;
}