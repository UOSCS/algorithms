#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    string str;

    cin >> str;

    map<string, char> m;

    m["AA"] = 'A', m["AG"] = 'C', m["AC"] = 'A', m["AT"] = 'G';
    m["GA"] = 'C', m["GG"] = 'G', m["GC"] = 'T', m["GT"] = 'A';
    m["CA"] = 'A', m["CG"] = 'T', m["CC"] = 'C', m["CT"] = 'G';
    m["TA"] = 'G', m["TG"] = 'A', m["TC"] = 'G', m["TT"] = 'T';

    while(N > 1)
    {
        string tmp = str.substr(N - 2, 2);

        str.erase(N - 2, 2);

        str += m[tmp];

        N--;
    }

    cout << str;

    return 0;
}