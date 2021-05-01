#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    string s;
    vector<char> v;

    cin >> N >> K >> s;

    for(int i = 0; i < s.size(); i++)
    {
        while(K && !v.empty() && v.back() < s[i])
        {
            v.pop_back();
            K--;
        }
        v.push_back(s[i]);
    }
    while(K--)
        v.pop_back();

    for(int i = 0; i < v.size(); i++)
        cout << v[i];

    return 0;
}