#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    while(true)
    {
        string str;

        cin >> str;

        if(str == "#")
            break;

        int octal = 1, answer = 0;

        for(int i = str.length() - 1; i >= 0; i--)
        {
            int digit;

            switch (str[i])
            {
                case '-':
                    digit = 0;
                    break;
                case '\\':
                    digit = 1;
                    break;
                case '(':
                    digit = 2;
                    break;
                case '@':
                    digit = 3;
                    break;
                case '?':
                    digit = 4;
                    break;
                case '>':
                    digit = 5;
                    break;
                case '&':
                    digit = 6;
                    break;
                case '%':
                    digit = 7;
                    break;
                case '/':
                    digit = -1;
                    break;
                default:
                    break;
            }

            answer += digit * octal;

            octal <<= 3;
        }

        cout << answer << '\n';
    }
}