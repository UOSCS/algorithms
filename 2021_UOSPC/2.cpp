#include <iostream>
#include <queue>
#include <cstring>

#define DIV_NUM 1000000007

using namespace std;

long long arr[11];
long long tmp[11];
vector<int> v[11];

void bfs(int V, int T)
{
    queue<int> q;

    q.push(1);

    while(T--)
    {
        int i = q.size();

        while(i--)
        {
            int current = q.front();

            q.pop();

            if(!arr[current]) continue;

            for(int j = 0; j < v[current].size(); j++)
            {
                tmp[v[current][j]] += arr[current];

                tmp[v[current][j]] %= DIV_NUM;

                q.push(v[current][j]);
            }

            arr[current] = 0;
        }

        for(int j = 1; j <= V; j++)
            arr[j] = tmp[j];

        memset(tmp, 0, sizeof(tmp));
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    int V, E, T;

    cin >> V >> E >> T;

    for(int i = 0; i < E; i++)
    {
        int tmp1, tmp2;

        cin >> tmp1 >> tmp2;

        v[tmp1].push_back(tmp2), v[tmp2].push_back(tmp1);
    }

    arr[1] = 1;

    bfs(V, T);

    long long sum = 0;

    for(long long i : arr)
        sum += i;

    sum %= DIV_NUM;

    cout << sum;

    return 0;
}