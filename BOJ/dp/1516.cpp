#include <iostream>
#include <vector>

using namespace std;

int time[501], dp_cache[501];
vector<int> arr[501];

int dp(int n)
{
    if(!dp_cache[n])
    {
        int tmp = 0;
        for(int i = 0; i < arr[n].size(); i++)
            tmp = max(tmp, dp(arr[n][i]));
        dp_cache[n] += tmp + time[n];
    }

    return dp_cache[n];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> time[i];
        while(true)
        {
            int tmp;
            cin >> tmp;
            if(tmp == -1)
                break;
            else
                arr[i].push_back(tmp);
        }
    }

    for(int i = 1; i <= N; i++)
        cout << dp(i) << '\n';

    return 0;
}