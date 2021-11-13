#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string str, key;

    getline(cin, str), getline(cin, key);

    for(int i = 0, j = 0; i < str.length(); i++, j++)
    {
        if(j >= key.length()) j = 0;

        if(str[i] == ' ') cout << ' ';
        else if(str[i] <= key[j])
        {
            char c = str[i];

            c += 26;

            c -= key[j] - 'a' + 1;

            cout << c;
        }
        else if(str[i] > key[j]) cout << (char) (str[i] - key[j] + 'a' - 1);
    }

    return 0;
}