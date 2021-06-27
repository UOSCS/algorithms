#include <iostream>
#include <regex>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;
    regex re("(100+1+|01)+");

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        string s;
        cin >> s;
        cout << (regex_match(s, re) ? "YES" : "NO") << '\n';
    }

    return 0;
}