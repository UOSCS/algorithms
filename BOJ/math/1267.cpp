#include <iostream>

using namespace std;

int calc_payment(int divisor, int payment, int arr[], int N)
{
    int total_payment = 0;

    for(int i = 0; i < N; i++)
        total_payment += ((arr[i] / divisor) + 1) * payment;

    return total_payment;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N, arr[20], Y, M;

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    Y = calc_payment(30, 10, arr, N);
    M = calc_payment(60, 15, arr, N);

    if(Y == M)
        cout << "Y M " << Y;
    else if(Y > M)
        cout << "M " << M;
    else
        cout << "Y " << Y;
}