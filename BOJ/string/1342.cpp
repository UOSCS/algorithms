#include <iostream>

using namespace std;

int arr[26], ans;

void dfs(int prev, int depth, int n)
{
    if(depth == n)
        ans++;
    for(int i = 0; i < 26; i++)
        if(i != prev && arr[i])
        {
            arr[i]--;
            dfs(i, depth + 1, n);
            arr[i]++;
        }
}

int main(void)
{
    ios::sync_with_stdio(0);

    string S;

    cin >> S;

    for(int i = 0; i < S.length(); i++)
        arr[S[i] - 'a']++;
    dfs(-1, 0, S.length());

    cout << ans;

    return 0;
}