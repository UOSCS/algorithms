#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string S, T;
    bool flag = false;

    cin >> S >> T;

    while(T.length() >= S.length())
    {
        if(S == T)
        {
            flag = true;
            break;
        }
        char tmp = T.back();
        T.erase(T.end() - 1);
        if(tmp == 'B')
            reverse(T.begin(), T.end());
    }

    cout << flag ? 1 : 0;

    return 0;
}