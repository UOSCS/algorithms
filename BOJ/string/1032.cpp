#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;
    string arr[50];

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    bool flag[50] = {false};

    for(int i = 1; i < N; i++)
        for(int j = 0; j < arr[i].length(); j++)
            if(arr[0][j] != arr[i][j])
                flag[j] = true;

    for(int i = 0; i < arr[0].length(); i++)
        if(flag[i]) cout << '?';
        else cout << arr[0][i];

    return 0;
}