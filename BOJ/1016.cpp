#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    long long low, high;
    bool flag[1000001] = {false};

    cin >> low >> high;

    for(long long i = 2; i * i <= high; i++)
    {
        long long quotient = low / (i * i);

        if(low % (i * i))
            quotient++;

        for(long long j = quotient * (i * i); j <= high; j += (i * i))
            flag[j - low] = true;
    }

    int count = 0;

    for(int i = 0; i <= high - low; i++)
        if(!flag[i])
            count++;

    cout << count;
    
    return 0;
}