#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    cin >> N;
    for(int i = 0, num; i < N; i++)
    {
        cin >> num;
        if(i & 1)
            min_heap.push(num);
        else
            max_heap.push(num);
        if(!min_heap.empty() && !max_heap.empty() && min_heap.top() < max_heap.top())
        {
            int tmp1 = max_heap.top();
            int tmp2 = min_heap.top();
            max_heap.pop(); min_heap.pop();
            max_heap.push(tmp2); min_heap.push(tmp1);
        }
        cout << max_heap.top() << '\n';
    }

    return 0;
}