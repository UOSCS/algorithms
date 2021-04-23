#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, arr[100000], max_weight;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    sort(arr, arr + N, greater<int>());
    max_weight = arr[0];
    for(int i = 1; i < N; i++)
        if(max_weight < (arr[i] * (i + 1)))
            max_weight = arr[i] * (i + 1);
    
    cout << max_weight << '\n';

    return 0;
}