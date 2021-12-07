#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string str;

    getline(cin, str);

    bool flag[26] = {false};

    char base = 'a';

    flag['a' - base] = flag['e' - base] = flag['i' - base] = flag['o' - base] = flag['u' - base] = true;

    for(int i = 0; i < str.length(); i++)
    {
        cout << str[i];

        if(flag[str[i] - base])
            i += 2;
    }

    return 0;
}