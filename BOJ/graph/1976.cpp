#include <iostream>
#include <cstring>

using namespace std;

int N, M, parent[201];

int find(int node)
{
    if(parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);
}

void merge(int i, int j)
{
    i = find(i), j = find(j);

    if(abs(parent[i]) >= abs(parent[j]))
    {
        parent[i] += parent[j];
        parent[j] = i;
    }
    else
    {
        parent[j] += parent[i];
        parent[i] = j;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    bool result = true;

    memset(parent, -1, sizeof(parent));

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            bool is_connected;

            cin >> is_connected;

            if(is_connected && find(i) != find(j))
                merge(i, j);
        }
        
    for(int i = 0, root; i < M; i++)
    {
        int tmp;

        cin >> tmp;

        if(!i)
            root = tmp;
        else if(find(root) != find(tmp))
        {
            result = false;
            break;
        }
    }

    cout << (result ? "YES" : "NO");

    return 0;
}
