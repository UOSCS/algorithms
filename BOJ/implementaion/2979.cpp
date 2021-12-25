#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int A, B, C;

    cin >> A >> B >> C;

    B <<= 1;
    C *= 3;

    int low[3], high[3];

    for(int i = 0; i < 3; i++)
        cin >> low[i] >> high[i];

    sort(low, low + 3), sort(high, high + 3);

    int low_ptr = 0, high_ptr = 0, cnt = 0, fee = 0;

    for(int i = low[0]; i <= high[2]; i++)
    {
        while(low_ptr < 3 && i == low[low_ptr])
            cnt++, low_ptr++;

        while(high_ptr < 3 && i == high[high_ptr])
            cnt--, high_ptr++;

        if(cnt == 1) fee += A;
        else if(cnt == 2) fee += B;
        else if(cnt == 3) fee += C;
    }

    cout << fee;

    return 0;
}