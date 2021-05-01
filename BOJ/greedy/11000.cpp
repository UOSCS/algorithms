#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> arr[200000];
    priority_queue<int, vector<int>, greater<int>> pq;
    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + N);
    pq.push(arr[0].second);
    for(int i = 1; i < N; i++)
    {
        if(arr[i].first >= pq.top())
            pq.pop();
        pq.push(arr[i].second);
    }

    cout << pq.size() << '\n';

    return 0;
}