#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string a, b;

    cin >> a >> b;

    if(a.length() < b.length())
        swap(a, b);

    string zeros(a.length() - b.length(), '0');

    b = zeros + b;

    int carry = 0;

    string answer = "";

    for(int i = a.length() - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;

        char digit = (sum % 2) + '0';

        answer = digit + answer;

        carry = sum >> 1;

        if(!i && carry)
            answer = to_string(carry) + answer;
    }

    int i = 0;

    while(answer[i] == '0')
        i++;

    if(i == answer.length())
        cout << '0';
    else
    {
        answer.erase(0, i);

        cout << answer;
    }

    return 0;
}