#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string s;

    cin >> s;

    while(s.length() % 3)
        s = '0' + s;

    map<string, char> m;

    m["000"] = '0', m["001"] = '1', m["010"] = '2', m["011"] = '3';
    m["100"] = '4', m["101"] = '5', m["110"] = '6', m["111"] = '7';

    string answer = "";

    for(int i = s.length() - 3; i >= 0; i -= 3)
        answer += m[s.substr(i, 3)];

    for(int i = answer.length() - 1; i >= 0; i--)
        cout << answer[i];

    return 0;
}