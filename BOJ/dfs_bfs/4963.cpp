#include <iostream>
#include <cstring>

using namespace std;

bool visited[50][50], map[50][50];
int W, H, dw[8] = {-1, 0, 1, 1, 1, 0, -1, -1}, dh[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

void dfs(int h, int w)
{
    visited[h][w] = true;

    for(int i = 0; i < 8; i++)
    {
        int new_w = w + dw[i], new_h = h + dh[i];

        if((new_w < W && new_w >= 0 && new_h < H && new_h >= 0) 
            && !visited[new_h][new_w] && map[new_h][new_w])
            dfs(new_h, new_w);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        int ans = 0;

        cin >> W >> H;

        if(!W && !H)
            break;
        
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                cin >> map[i][j];

        memset(visited, false, sizeof(visited));

        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                if(!visited[i][j] && map[i][j])
                {
                    ans++;
                    dfs(i, j);
                }

        cout << ans << '\n';
    }
    
    return 0;
}