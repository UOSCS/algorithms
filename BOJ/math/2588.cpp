#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string a, b;

    cin >> a >> b;

    int a_to_int = stoi(a);

    for(int i = 2; i >= 0; i--)
        cout << a_to_int * (b[i] - '0') << '\n';
    
    cout << stoi(a) * stoi(b);

    return 0;
}