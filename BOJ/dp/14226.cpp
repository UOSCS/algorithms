#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

bool visited[2000][2000];
int S;

int bfs()
{
    queue<pii> q;
    int clock = 0;

    visited[1][0] = true;
    q.push({ 1, 0 });
    while(true)
    {
        int i = q.size();
        while(i--)
        {
            pii tmp = q.front();
            q.pop();
            if(tmp.first == S)
                return clock;
            if(!visited[tmp.first][tmp.first])
            {
                visited[tmp.first][tmp.first] = true;
                q.push({ tmp.first, tmp.first });
            }
            if(tmp.first < S && !visited[tmp.first + tmp.second][tmp.second])
            {
                visited[tmp.first + tmp.second][tmp.second] = true;
                q.push({ tmp.first + tmp.second, tmp.second });
            }
            if(tmp.first > 0 && !visited[tmp.first - 1][tmp.second])
            {
                visited[tmp.first - 1][tmp.second] = true;
                q.push({ tmp.first - 1, tmp.second });
            }
        }
        clock++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;

    cout << bfs();

    return 0;
}