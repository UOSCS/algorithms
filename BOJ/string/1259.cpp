#include <iostream>

using namespace std;

bool is_palindrome(string& n, int l, int r)
{
    if(l > r)
        return true;

    if(n[l] == n[r])
        return is_palindrome(n, l + 1, r - 1);
    else
        return false;
}

int main(void)
{
    ios::sync_with_stdio(0);

    while(true)
    {
        string n;

        cin >> n;

        if(n == "0") break;

        if(is_palindrome(n, 0, n.size() - 1)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}