#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;
    bool arr[100];

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int score = 0, cumul = 1;

    for(int i = 0; i < N; i++)
        if(arr[i])
            score += cumul++;
        else
            cumul = 1;

    cout << score;

    return 0;
}