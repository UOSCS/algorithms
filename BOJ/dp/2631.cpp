#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, arr[201], dp[201], result = 0;

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    
    for(int i = 1; i <= N; i++)
    {
        int tmp = 0;
        for(int j = 0; j < i; j++)
            if(tmp < dp[j] && arr[i] > arr[j])
                tmp = dp[j];
        dp[i] = tmp + 1;
        result = result < dp[i] ? dp[i] : result;
    }

    cout << N - result;

    return 0;
}