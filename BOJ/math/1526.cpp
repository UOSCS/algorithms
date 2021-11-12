#include <iostream>

using namespace std;

bool calc(int N)
{
    bool flag = true;

    while(N)
    {
        int tmp = N % 10;

        if(!(tmp == 4 || tmp == 7))
        {
            flag = false;

            break;
        }

        N /= 10;
    }

    return flag;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    for(int i = N; i >= 4; i--)
        if(calc(i))
        {
            cout << i;

            break;
        }

    return 0;
}