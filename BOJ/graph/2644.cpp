#include <iostream>
#include <queue>

using namespace std;

vector<int> v[101];
int ans;
bool visited[101];

void bfs(int start, int end)
{
    queue<int> q;

    for(int i = 0; i < v[start].size(); i++)
    {
        q.push(v[start][i]);
        visited[v[start][i]] = true;
    }

    while(!q.empty())
    {
        int i = q.size();

        ans++;

        while(i--)
        {
            int node = q.front();

            q.pop();

            if(node == end)
                return;
            
            for(int i = 0; i < v[node].size(); i++)
                if(!visited[v[node][i]])
                {
                    q.push(v[node][i]);
                    visited[v[node][i]] = true;
                }
        }
    }

    ans = -1;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int n, m, person1, person2;

    cin >> n >> person1 >> person2 >> m;
    for(int i = 0; i < m; i++)
    {
        int tmp1, tmp2;

        cin >> tmp1 >> tmp2;

        v[tmp1].push_back(tmp2); v[tmp2].push_back(tmp1);
    }

    bfs(person1, person2);

    cout << ans;

    return 0;
}