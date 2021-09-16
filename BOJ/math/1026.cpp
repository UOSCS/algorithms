#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, A[50], B[50];

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++)
        cin >> B[i];

    sort(A, A + N);
    sort(B, B + N, greater<int>());

    int sum = 0;

    for(int i = 0; i < N; i++)
        sum += A[i] * B[i];

    cout << sum;

    return 0;
}