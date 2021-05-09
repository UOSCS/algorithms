#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];
int parent[100001];

void find_parent(int node)
{
    for(int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        if(!parent[next])
        {
            parent[next] = node;
            find_parent(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    parent[1] = 1;
    find_parent(1);
    for(int i = 2; i <= N; i++)
        cout << parent[i] << '\n';

    return 0;
}