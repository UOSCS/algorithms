#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, K;
    priority_queue<int> pq;    

    cin >> N >> K;

    while(N)
    {
        int i = 0;

        while(true)
        {
            if(1 << i > N)
                break;
            
            i++;
        }

        i--;
    
        pq.push(-(1 << i));

        N -= 1 << i;
    }

    int adding = 0;

    while(pq.size() > K)
    {
        int a, b;

        a = pq.top(), pq.pop();
        b = pq.top(), pq.pop();

        adding += a - b;

        pq.push(-(-b << 1));
    }

    cout << adding;

    return 0;
}