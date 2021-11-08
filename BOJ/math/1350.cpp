#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    int arr[50];

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int size_cluster;

    cin >> size_cluster;

    long long total = 0;

    for(int i = 0; i < N; i++)
        total += (arr[i] + size_cluster - 1) / size_cluster;

    cout << total * size_cluster;

    return 0;
}