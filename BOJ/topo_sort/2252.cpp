#include <iostream>
#include <vector>

using namespace std;

vector<int> v[32001];
bool flag[32001];

void topo_sort(int node)
{
    if(flag[node])
        return;
    if(v[node].size())
    {
        for(int i = 0; i < v[node].size(); i++)
            if(!flag[v[node][i]])
                topo_sort(v[node][i]);
    }
    cout << node << ' ';
    flag[node] = true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        v[v2].push_back(v1);
    }

    for(int i = 1; i <= N; i++)
        topo_sort(i);

    return 0;
}