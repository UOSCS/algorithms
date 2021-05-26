#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<pii> p[10001];
int weight;
bool visited[10001];

void prim()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    visited[1] = true;
    for(int i = 0; i < p[1].size(); i++)
        pq.push(p[1][i]);

    while(!pq.empty())
    {
        pii v = pq.top();
        int t = v.second;

        pq.pop();
        if(!visited[t])
        {
            weight += v.first;
            for(int i = 0; i < p[t].size(); i++)
            {
                visited[t] = true;
                pq.push(p[t][i]);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E;

    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        p[v1].push_back({ cost, v2 }); p[v2].push_back({ cost, v1 });
    }

    prim();

    cout << weight;

    return 0;
}