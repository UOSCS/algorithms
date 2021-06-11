#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    priority_queue<int> pq;
    vector<pair<int, int>> v;
    int n, answer = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int d, p;
        cin >> p >> d;
        v.push_back({ d, p });
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        int d = v[i].first, p = v[i].second;
        pq.push(-p);
        if(d < pq.size())
            pq.pop();
    }
    while(pq.size())
        answer += pq.top(), pq.pop();
    
    cout << -answer;

    return 0;
}