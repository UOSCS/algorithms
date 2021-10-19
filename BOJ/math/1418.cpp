#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, K, arr[100001] = {0};

    cin >> N >> K;

    for(int i = 2; i <= N; i++)
        if(!arr[i])
            for(int j = i; j <= N; j += i)
                arr[j] = max(arr[j], i);

    int count = 0;

    for(int i = 1; i <= N; i++)
        if(arr[i] <= K)
            count++;

    cout << count;

    return 0;
}