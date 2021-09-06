#include <iostream>

using namespace std;

long long count[10];

void calc(int n, long long multiplier)
{
    while(n)
    {
        count[n % 10] += multiplier;
        n /= 10;
    }
}

void adjust_low(int& low, int high, int multiplier)
{
    while(low % 10 && low <= high)
    {
        calc(low, multiplier);
        low++;
    }
}

void adjust_high(int low, int& high, int multiplier)
{
    while(high % 10 != 9 && low <= high)
    {
        calc(high, multiplier);
        high--;
    }
}

void solve(int low, int high)
{
    long long multiplier = 1;

    while(true)
    {
        adjust_low(low, high, multiplier), adjust_high(low, high, multiplier);

        if(low > high)
            return;

        low /= 10, high /= 10;

        long long plus = (high - low + 1) * multiplier;

        for(int i = 0; i < 10; i++)
            count[i] += plus;

        multiplier *= 10;
    }
}

void print_result()
{
    for(long long i : count)
        cout << i << ' ';
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    solve(1, N);

    print_result();

    return 0;
}