#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, arr[51] = {0};

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int tmp;

        cin >> tmp;

        arr[tmp]++;
    }

    for(int i = 50; i >= 0; i--)
    {
        if(arr[i] == i)
        {
            cout << i;

            break;
        }

        if(!i) cout << -1;
    }

    return 0;
}