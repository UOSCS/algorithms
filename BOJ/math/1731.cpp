#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, arr[50];

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    bool flag = true;

    int diff = arr[1] - arr[0];

    for(int i = 1; i < N - 1; i++)
    {
        if(arr[i + 1] - arr[i] != diff)
        {
            flag = false;

            break;
        }

        diff = arr[i + 1] - arr[i];
    }

    if(flag) cout << arr[N - 1] + diff;
    else cout << arr[N - 1] * (arr[1] / arr[0]);

    return 0;
}