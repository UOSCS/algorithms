#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> jewels[300000];
int bags[300000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> pq;
    int N, K, index = 0;
    long long sum = 0;

    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> jewels[i].first >> jewels[i].second;
    for(int i = 0; i < K; i++)
        cin >> bags[i];

    sort(jewels, jewels + N);
    sort(bags, bags + K);
    for(int i = 0; i < K; i++)
    {
        while(jewels[index].first <= bags[i] && index < N)
            pq.push(jewels[index++].second);
        if(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum << '\n';

    return 0;
}