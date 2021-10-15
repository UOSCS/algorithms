#include <iostream>

using namespace std;

int calc(string& n, int pos, int npos)
{
    int num = 1;

    for(int i = 0; i < npos; i++)
        num *= n[pos + i] - '0';

    return num;
}

int main(void)
{
    ios::sync_with_stdio(0);

    string n;

    cin >> n;

    bool flag = false;

    int a = 1, b = 1;

    for(int i = 1; i < n.size(); i++)
    {
        int a = calc(n, 0, i);

        int b = calc(n, i, n.size() - i);

        if(a == b)
        {
            flag = true;

            break;
        }
    }

    cout << (flag ? "YES" : "NO");

    return 0;
}