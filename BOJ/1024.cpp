#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, L;

    cin >> N >> L;

    int base_num = 1;
    bool flag = true;

    while(true)
    {
        if(L > 100 || base_num < 0)
        {
            flag = false;
            break;
        }

        int sum;
        
        if(L & 1)
            sum = ((((base_num << 1) + L - 1) * (L - 1)) >> 1) + (base_num + ((L - 1) >> 1));
        else
            sum = (((base_num << 1) + L - 1) * L) >> 1;

        if(sum == N)
            break;
        else
        {
            double bias = ((double)N - sum) / L;

            if(bias != (int) bias)
            {
                L++;
                base_num = 1;
            }
            else
                base_num += bias;
        }
    }

    if(flag)
        for(int i = 0; i < L; i++)
            cout << base_num + i << ' ';
    else
        cout << -1;

    return 0;
}