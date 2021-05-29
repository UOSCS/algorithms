#include <iostream>
#include <string>

using namespace std;

int arr[1001], dp[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, result_len = 0, result_idx = 0;
    string s[1001];

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    for(int i = 1; i <= N; i++)
    {
        int max_len = 0, max_idx = 0;
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j] && max_len < dp[j])
            {
                max_len = dp[j];
                max_idx = j;
            }
        dp[i] = max_len + 1;
        s[i] = (max_idx ? s[max_idx] : "") + to_string(arr[i]) + " ";
        if(result_len < dp[i])
        {
            result_len = dp[i];
            result_idx = i;
        }
    }

    cout << result_len << '\n';
    cout << s[result_idx];

    return 0;
}