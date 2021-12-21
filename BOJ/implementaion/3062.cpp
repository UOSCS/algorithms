#include <iostream>
#include <algorithm>

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

    int T;

    cin >> T;

    while(T--)
    {
        string str;

        cin >> str;

        string rev_str = str;

        reverse(rev_str.begin(), rev_str.end());

        string sum = to_string(stoi(str) + stoi(rev_str));

        cout << (is_palindrome(sum, 0, sum.length() - 1) ? "YES" : "NO") << '\n';
    }

    return 0;
}