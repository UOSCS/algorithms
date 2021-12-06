#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string str;

    cin >> str;

    for(int i = 0; i < str.length(); i++)
        if(str[i] >= 65 && str[i] <= 90)
            cout << (char) (str[i] + 32);
        else if(str[i] >= 97 && str[i] <= 122)
            cout << (char) (str[i] - 32);

    return 0;

}