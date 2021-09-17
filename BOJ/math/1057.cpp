#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, A, B;

    cin >> N >> A >> B;

    A--, B--;

    if(B < A)
        swap(A, B);

    int round = 1;

    while(true)
    {
        if(A == B - 1 && (!(A & 1) && (B & 1)))
            break;

        A >>= 1, B >>= 1, round++;
    }

    cout << round;

    return 0;
}