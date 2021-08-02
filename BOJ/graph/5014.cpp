#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int F, S, G, U, D;

int bfs(int start)
{
    queue<int> q;
    int ans = 0;
    bool visited[1000001];

    memset(visited, false, sizeof(visited));
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int i = q.size();

        while(i--)
        {
            int current = q.front();

            q.pop();

            if(current == G)
                return ans;

            if(U && current + U <= F && !visited[current + U])
            {
                q.push(current + U);
                visited[current + U] = true;
            }
            if(D && current - D >= 1 && !visited[current - D])
            {
                q.push(current - D);
                visited[current - D] = true;
            }
        }

        ans++;
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> F >> S >> G >> U >> D;

    int ans = bfs(S);

    ans >= 0 ? (cout << ans) : (cout << "use the stairs");

    return 0;
}