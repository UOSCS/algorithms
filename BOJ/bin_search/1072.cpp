#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    long long X, Y;

    cin >> X >> Y;

    long long Z = (Y * 100) / X;

    if(Z == 100 || Z == 99)
        cout << -1;
    else
    {
        int low = 1, high = 1000000000;

        while(low < high)
        {
            long long mid = (low + high) >> 1;
            long long new_Z = ((Y + mid) * 100) / (X + mid);

            if(new_Z > Z)
                high = mid;
            else
                low = mid + 1;
        }

        cout << high;
    }

    return 0;
}