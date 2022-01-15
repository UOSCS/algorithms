#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, score, P;

    cin >> N >> score >> P;

    int arr[50];

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    if(!N) cout << 1;
    else
    {
        int seq = 0;

        for(int i = 0; i < N; i++)
            if(score >= arr[i])
            {
                seq = i + 1;

                break;
            }
        
        if(!seq) seq = N + 1;

        if(N < P) cout << seq;
        else
        {
            if(seq > P) cout << -1;
            else if(arr[P - 1] == score) cout << -1;
            else cout << seq;
        }
    }

    return 0;
}