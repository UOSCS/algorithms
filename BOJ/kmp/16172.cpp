#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

vector<int> get_ki(string k)
{
    int k_len = k.length(), j = 0;
    vector<int> ki(k_len, 0);

    for(int i = 1; i < k_len; i++)
    {
        while(j > 0 && k[i] != k[j])
            j = ki[j - 1];
        if(k[i] == k[j])
            ki[i] = ++j;
    }

    return ki;
}

bool kmp(string s, string k)
{
    int s_len = s.length(), k_len = k.length(), j = 0;
    vector<int> ki = get_ki(k);

    for(int i = 0; i < s_len; i++)
    {
        if(isdigit(s[i]))
            continue;
        while(j > 0 && s[i] != k[j])
            j = ki[j - 1];
        if(s[i] == k[j])
            if(j == k_len - 1)
                return true;
            else
                j++;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);

    string S, K;

    cin >> S >> K;

    cout << kmp(S, K) ? 1 : 0;

    return 0;
}