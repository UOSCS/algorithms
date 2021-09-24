#include <iostream>
#include <queue>

using namespace std;

long long calc(int N)
{
    queue<long long> q;

    if(N >= 0 && N < 10)
        return N;

    for(int i = 1; i < 10; i++)
        q.push(i);

    int sequence = 9;

    while(!q.empty())
    {
        long long current_num = q.front();

        q.pop();

        int last_digit = current_num % 10;

        for(int i = 0; i < last_digit; i++)
        {
            long long next_num = current_num * 10 + i;

            if(++sequence == N)
                return next_num;

            q.push(next_num);
        }
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    cout << calc(N);

    return 0;
}