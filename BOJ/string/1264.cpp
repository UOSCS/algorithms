#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    map<char, int> m;

    m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 1;

    m['A'] = m['E'] = m['I'] = m['O'] = m['U'] = 1;

    while(true)
    {
        string s;

        getline(cin, s);

        if(s == "#")
            break;

        int count = 0;

        for(int i = 0; i < s.size(); i++)
            if(m[s[i]])
                count++;

        cout << count << '\n';
    }

    return 0;
}