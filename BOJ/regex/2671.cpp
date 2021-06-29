#include <iostream>
#include <regex>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string s;
    regex re("(100+1+|01)+");

    cin >> s;

    cout << (regex_match(s, re) ? "SUBMARINE" : "NOISE");

    return 0;
}