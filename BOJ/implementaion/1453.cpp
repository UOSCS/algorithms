#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;
    bool arr[100] = {false};

    cin >> N;

    int count = 0;

    for(int i = 0; i < N; i++)
    {
        int tmp;

        cin >> tmp;

        if(arr[tmp]) count++;
        else arr[tmp] = true;
    }

    cout << count;

    return 0;
}