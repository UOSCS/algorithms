#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    pair<int, int> p;
    int N, arr[100001], start, end, answer = 2000000000;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    start = 0; end = N - 1;
    while(start < end)
    {
        if(answer > abs(arr[start] + arr[end]))
        {
            p = { arr[start], arr[end] };
            answer = abs(arr[start] + arr[end]);
        }
        if(arr[start] + arr[end] < 0)
            start++;
        else
            end--;
    }

    cout << p.first << ' ' << p.second;

    return 0;
}