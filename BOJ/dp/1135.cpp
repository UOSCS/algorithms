#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[50];
int dp[50];

int dfs(int n)
{
    if(dp[n])
        return dp[n];
    if(!v[n].size())
        return 1;
    
    vector<int> arr;
    int ret = 0;

    for(int i : v[n])
        arr.push_back(dfs(i));
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 0; i < arr.size(); i++)
        ret = max(ret, arr[i] + i);

    return dp[n] = ret + 1;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp >= 0)
            v[tmp].push_back(i);
    }

    cout << dfs(0) - 1;

    return 0;
}