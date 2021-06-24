#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, S, arr[100000], answer = 100001, start = 0, end = 0, p_sum = 0;

    cin >> N >> S;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    while(end <= N)
        if(p_sum < S)
            p_sum += arr[end++];
        else
        {
            answer = min(answer, end - start);
            p_sum -= arr[start++];
        }

    cout << (answer == 100001 ? 0 : answer);

    return 0;
}