#include <iostream>

using namespace std;

bool is_palindrome(string str, int low, int high)
{
    if(low > high)
        return true;

    if(str[low] == str[high])
        return is_palindrome(str, low + 1, high - 1);
    else
        return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        string str;

        cin >> str;

        if(str == "0") break;

        int cnt = 0, str_length = str.length();

        while(true)
        {
            if(is_palindrome(str, 0, str_length - 1))
            {
                cout << cnt << '\n';

                break;
            }
            else
            {
                str = to_string(stoi(str) + 1);

                if(str.length() < str_length)
                {
                    int padding = str_length - str.length();

                    while(padding--)
                        str = '0' + str;
                }

                cnt++;
            }
        }
    }
}