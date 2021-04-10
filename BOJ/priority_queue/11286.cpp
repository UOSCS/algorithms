#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    priority_queue<p, vector<p>, greater<p>> pq;

    cin >> N;
    for(int i = 0, num; i < N; i++)
    {
        cin >> num;
        if(!num)
        {
            if(pq.empty())
                cout << "0\n";
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else
            pq.push(make_pair(abs(num), num));
    }

    return 0;
}