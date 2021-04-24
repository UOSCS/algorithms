#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    int N, sum = 0;

    cin >> N;
    for(int i = 0, tmp; i < N; i++)
    {
        cin >> tmp;
        pq.push(tmp);
    }

    while(pq.size() > 1)
    {
        int tmp1, tmp2;
        tmp1 = pq.top(); pq.pop();
        tmp2 = pq.top(); pq.pop();
        pq.push(tmp1 + tmp2);
        sum += tmp1 + tmp2;
    }

    cout << sum << '\n';

    return 0;
}