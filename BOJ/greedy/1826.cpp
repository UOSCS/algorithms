#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int main(void)
{
    ios::sync_with_stdio(0);

    vector<p> v;
    priority_queue<int> pq;
    int N, L, P, i, answer = 0;

    cin >> N;
    for(i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    cin >> L >> P;

    sort(v.begin(), v.end());
    i = 0;
    while(L > P)
    {
        int add;
        while(i < v.size() && v[i].first <= P)
            pq.push(v[i++].second);
        if(pq.empty())
        {
            answer = -1;
            break;
        }
        add = pq.top(), pq.pop();
        P += add;
        answer++;
    }

    cout << answer;

    return 0;
}