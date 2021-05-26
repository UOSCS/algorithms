#include <iostream>
#include <queue>

using namespace std;

vector<int> v[1001];
int degree[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    queue<int> q;
    vector<int> result;
    int N, M, check = 0;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int n, arr[1000];
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> arr[j];
            if(j)
                degree[arr[j]]++;
        }
        for(int j = 0; j < n - 1; j++)
            v[arr[j]].push_back(arr[j + 1]);
    }

    for(int i = 1; i <= N; i++)
        if(!degree[i])
            q.push(i);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        check++;
        for(int i : v[tmp])
            if(!(--degree[i]))
                q.push(i);
        result.push_back(tmp);
    }
    if(check < N)
        cout << 0;
    else
        for(int i : result)
            cout << i << '\n';

    return 0;
}