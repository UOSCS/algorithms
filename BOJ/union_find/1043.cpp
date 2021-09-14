#include <iostream>

using namespace std;

int parent[51];

int find(int node)
{
    if(!parent[node]) return node;

    return parent[node] = find(parent[node]);
}

void merge(int a, int b)
{
    parent[find(b)] = find(a);
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M, true_n;
    int true_people[50], party[50][50];

    cin >> N >> M >> true_n;
    for(int i = 0; i < true_n; i++)
        cin >> true_people[i];

    for(int i = 0; i < M; i++)
    {
        int party_n;

        cin >> party_n >> party[i][0];

        for(int j = 1; j < party_n; j++)
        {
            cin >> party[i][j];

            if(find(party[i][0]) != find(party[i][j]))
                merge(party[i][0], party[i][j]);
        }
    }

    int count = 0;

    for(int i = 0; i < M; i++)
    {
        bool flag = true;

        for(int j = 0; j < true_n; j++)
            if(find(party[i][0]) == find(true_people[j]))
            {
                flag = false;

                break;
            }

        if(flag) count++;
    }

    cout << count;

    return 0;
}