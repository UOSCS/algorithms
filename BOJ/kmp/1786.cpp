#include <iostream>
#include <vector>

using namespace std;

vector<int> get_pi(string p)
{
    int p_len = p.length(), j = 0;
    vector<int> pi(p_len, 0);

    for(int i = 1; i < p_len; i++)
    {
        while(j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }

    return pi;
}

vector<int> kmp(string s, string p)
{
    int s_len = s.length(), p_len = p.length(), j = 0;
    vector<int> pi = get_pi(p), ans;

    for(int i = 0; i < s_len; i++)
    {
        while(j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if(s[i] == p[j])
            if(j == p_len - 1)
            {
                ans.push_back(i - j + 1);
                j = pi[j];
            }
            else
                j++;
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);

    string S, P;
    vector<int> ans;

    getline(cin, S);
    getline(cin, P);

    ans = kmp(S, P);

    cout << ans.size() << '\n';
    for(int i : ans)
        cout << i << ' ';

    return 0;
}