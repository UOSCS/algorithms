#include <iostream>
#include <queue>

using namespace std;

vector<int> v[32001];
int degree[32001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    int N, M;

    cin >> N >> M;
    while(M--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        degree[v2]++;
    }

    for(int i = 1; i <= N; i++)
        if(!degree[i])
            pq.push(i);
    while(!pq.empty())
    {
        int tmp = pq.top();
        pq.pop();
        for(int i : v[tmp])
            if(!(--degree[i]))
                pq.push(i);
        cout << tmp << ' ';
    }

    return 0;
}