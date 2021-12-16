#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string str[3] = {"ascending", "descending", "mixed"};
    int arr[8];

    for(int i = 0; i < 8; i++)
        cin >> arr[i];

    int flag, seq;

    if(arr[0] == 1)
        flag = 0, seq = 1;
    else if(arr[0] == 8)
        flag = 1, seq = 8;
    else
        flag = 2;

    if(flag == 2)
        cout << str[flag];
    else
    {
        for(int i = 0; i < 8; i++)
            if(arr[i] != seq)
            {
                flag = 2;

                break;
            }
            else
                if(flag)
                    seq--;
                else
                    seq++;

        cout << str[flag];
    }

    return 0;
}