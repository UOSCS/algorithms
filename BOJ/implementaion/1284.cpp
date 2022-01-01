#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    while(true)
    {
        string str;

        cin >> str;

        if(str == "0") break;

        int width = 1;

        for(int i = 0; i < str.length(); i++)
            if(str[i] == '1') width += 3;
            else if(str[i] == '0') width += 5;
            else width += 4;

        cout << width << '\n';
    }

    return 0;
}