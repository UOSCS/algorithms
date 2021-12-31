#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int A, B, C, D;

    cin >> A >> B >> C >> D;

    int first_interval = A + B, second_interval = C + D;

    int arr[3];

    cin >> arr[0] >> arr[1] >> arr[2];

    for(int i = 0; i < 3; i++)
    {
        int count = 0;

        int remainder;

        remainder = (arr[i] - 1) % first_interval;

        if(remainder < A) count++;

        remainder = (arr[i] - 1) % second_interval;

        if(remainder < C) count++;

        cout << count << '\n';
    }

    return 0;
}