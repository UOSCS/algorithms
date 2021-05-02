#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int p[1001];

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

    int T, N, M;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        int count = 0;
        pair<int, int> arr[1000];
        memset(p, -1, sizeof(p));

        cin >> N >> M;
        for(int j = 0; j < M; j++)
            cin >> arr[j].first >> arr[j].second;

        sort(arr, arr + M, greater<pair<int, int>>());
        for(int j = 0; j < M; j++)
        {
            int tmp;
            tmp = find(arr[j].second);
            if(tmp >= arr[j].first)
            {
                count++;
                merge(tmp - 1, tmp);
            }
        }
        cout << count << '\n';
    }

    return 0;
}