#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string A, B;
    
    cin >> A >> B;

    long long A_sum = 0LL;

    for(int i = 0; i < A.length(); i++)
        A_sum += A[i] - '0';

    long long B_sum = 0LL;

    for(int j = 0; j < B.length(); j++)
        B_sum += B[j] - '0';

    cout << A_sum * B_sum;

    return 0;
}