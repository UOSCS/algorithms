#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int arr[9], sum = -100;
    bool flag[9] = {false};

    for(int i = 0; i < 9; i++)
        cin >> arr[i], sum += arr[i];

    for(int i = 0; i < 8; i++)
        for(int j = i + 1; j < 9; j++)
            if(arr[i] + arr[j] == sum)
            {
                flag[i] = flag[j] = true;

                break;
            }

    for(int i = 0; i < 9; i++)
        if(!flag[i])
            cout << arr[i] << '\n';

    return 0;
}