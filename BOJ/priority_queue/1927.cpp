#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    priority_queue<int, vector<int>, greater<int>> pq;

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
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(num);
    }

    return 0;
}