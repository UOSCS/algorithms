#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    while(true)
    {
        char c;

        cin >> c;

        if(c == '#') break;

        string str;

        getline(cin, str);

        int count = 0;

        for(int i = 0; i < str.length(); i++)
            if(str[i] == c || str[i] == c - 32)
                count++;

        cout << c << ' ' << count << '\n';
    }

    return 0;
}