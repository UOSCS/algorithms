#include <iostream>
#include <cstring>

using namespace std;

int p[100001];

int find(int node)
{
    if(p[node] < 0)
        return node;
    return p[node] = find(p[node]);
}

void merge(int prev, int next)
{
    int a = find(prev), b = find(next);

    p[b] = a;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int G, P, result = 0;

    memset(p, -1, sizeof(p));
    cin >> G >> P;
    for(int i = 0; i < P; i++)
    {
        int tmp, parent;
        cin >> tmp;
        parent = find(tmp);
        if(parent > 0)
        {
            result++;
            merge(parent - 1, parent);
        }
        else
            break;
    }

    cout << result << '\n';

    return 0;
}