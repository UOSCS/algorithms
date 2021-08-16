#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int parent[200001];

int find(int node)
{
    if(parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);
}

int merge(int a, int b)
{
    a = find(a), b = find(b);

    if(a == b)
        return -parent[a];
    
    if(-parent[a] < -parent[b])
    {
        parent[b] += parent[a];
        parent[a] = b;

        return -parent[b];
    }
    else
    {
        parent[a] += parent[b];
        parent[b] = a;

        return -parent[a];
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
        int F, idx = 1;
        map<string, int> name_index;

        memset(parent, -1, sizeof(parent));

        cin >> F;
        for(int i = 0; i < F; i++)
        {
            string s1, s2;

            cin >> s1 >> s2;

            if(!name_index[s1]) name_index[s1] = idx++;
            if(!name_index[s2]) name_index[s2] = idx++;

            cout << merge(name_index[s1], name_index[s2]) << '\n';
        }
    }

    return 0;
}