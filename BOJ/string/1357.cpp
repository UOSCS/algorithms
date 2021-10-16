#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string a, b;

    cin >> a >> b;

    reverse(a.begin(), a.end()), reverse(b.begin(), b.end());

    string c = to_string(stoi(a) + stoi(b));

    reverse(c.begin(), c.end());

    int i = 0;

    while(c[i] == '0')
        i++;
    
    c.erase(c.begin(), c.begin() + i);

    cout << c;

    return 0;
}