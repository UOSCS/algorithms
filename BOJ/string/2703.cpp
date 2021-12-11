#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    cin.ignore();

    while(T--)
    {
        string str, decrypt;

        getline(cin, str);

        getline(cin, decrypt);

        for(int i = 0; i < str.length(); i++)
            if(str[i] == ' ')
                cout << str[i];
            else
                cout << decrypt[str[i] - 'A'];
        
        cout << '\n';
    }

    return 0;
}