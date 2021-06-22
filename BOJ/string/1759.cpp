#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> arr;
int L, C;

void dfs(int idx, int c, int v, string str)
{
    int str_len = str.length();

    if(str_len == L)
    {
        if(c > 1 && v > 0)
            cout << str << '\n';
        return;
    }

    for(int i = idx; i < C - L + str_len + 1; i++)
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            dfs(i + 1, c, v + 1, str + arr[i]);
        else
            dfs(i + 1, c + 1, v, str + arr[i]);
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> L >> C;
    for(int i = 0; i < C; i++)
    {
        char tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());
    dfs(0, 0, 0, "");

    return 0;
}