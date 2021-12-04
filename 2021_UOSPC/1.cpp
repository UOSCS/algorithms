#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, arr[100001];
    
    cin >> N;
    
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    int answer = 100000, start = 0, end = 0;

    for(int i = 1; i <= N; i++)
    {
        if(arr[i])
        {
            if(start)
            {
                end = i;

                answer = min(answer, N - end + start);
            }

            start = i;
        }
    }

    int count = 1, i = 1;

    while(!arr[i++])
        count++;

    i = N;

    while(!arr[i--])
        count++;
    
    if(count < N)
        answer = min(answer, N - count);

    if(answer == 100000)
        cout << 0;
    else
        cout << answer;

    return 0;
}