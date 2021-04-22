#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(vector<int> v[], int is_visited[], int start)
{
    queue<int> q;
    int color[20001] = {0}, status = 1;

    q.push(start);
    is_visited[start] = 1;
    color[start] = status;
    while(1)
    {
        int i = q.size();

        if(!i)
            return 1;

        status = -status;
        while(i--)
        {
            int node = q.front();
            q.pop();
            for(int j = 0; j < v[node].size(); j++)
            {
                int tmp = v[node][j];
                if(!is_visited[tmp])
                {
                    q.push(tmp);
                    is_visited[tmp] = 1;
                    color[tmp] = status;
                }
                else if(color[tmp] == color[node])
                    return 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;

    cin >> K;
    for(int i = 0; i < K; i++)
    {
        int V, E, is_visited[20001] = {0}, result_flag = 0;
        cin >> V >> E;
        vector<int> v[V + 1];

        for(int j = 0, node1, node2; j < E; j++)
        {
            cin >> node1 >> node2;
            v[node1].push_back(node2); v[node2].push_back(node1);
        }

        for(int j = 1; j <= V; j++)
            if(!is_visited[j])
            {
                result_flag = bfs(v, is_visited, j);
                if(!result_flag)
                    break;
            }

        if(result_flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}