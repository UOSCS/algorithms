#include <iostream>
#include <queue>

using namespace std;

long long get_answer(int N)
{
    if(N <= 10)
        return N - 1;

    queue<long long> q;

    for(int i = 0; i < 10; i++)
        q.push(i);

    int count = 0;

    while(q.size())
    {
        count++;

        long long current_num = q.front();

        q.pop();

        if(count == N)
            return current_num;
        
        for(int i = 0; i < current_num % 10; i++)
            q.push(current_num * 10 + i);
    }

    return -1LL;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    cout << get_answer(N);

    return 0;
}