#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int main(void)
{
    ios::sync_with_stdio(0);

    priority_queue<int> pq;
    vector<p> v;
    int N, answer = 0;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int dead, ramen;
        cin >> dead >> ramen;
        v.push_back({ dead, ramen });
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        int dead = v[i].first, ramen = v[i].second;
        pq.push(-ramen);
        if(dead < pq.size())
            pq.pop();
    }
    while(pq.size())
        answer += pq.top(), pq.pop();

    cout << -answer;

    return 0;
}