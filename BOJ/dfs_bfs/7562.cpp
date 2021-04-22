#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int l, p start, p dest)
{
    queue<p> q;
    int is_visited[300][300] = {0}, count = 0;

    q.push(start);
    is_visited[start.first][start.second] = 1;
    while(1)
    {
        int i = q.size();

        while(i--)
        {
            p node = q.front();
            q.pop();

            if(node.first == dest.first && node.second == dest.second)
                return count;

            for(int j = 0; j < 8; j++)
            {
                int new_x = node.first + dx[j], new_y = node.second + dy[j];
                if((new_x >= 0 && new_x < l && new_y >= 0 && new_y < l) && 
                   !is_visited[new_x][new_y])
                {
                    q.push({ new_x, new_y });
                    is_visited[new_x][new_y] = 1;
                }
            }
        }

        count++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int l;
        p start, dest;
        
        cin >> l;
        cin >> start.first >> start.second;
        cin >> dest.first >> dest.second;

        cout << bfs(l, start, dest) << '\n';
    }
}