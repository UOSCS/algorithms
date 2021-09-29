#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;
int arr[100001], dp[100001];

void eratos(int B)
{
    for(int i = 2; i <= B; i++)
        arr[i] = i;

    for(int i = 2; i * i <= B; i++)
        if(arr[i])
            for(int j = i * i; j <= B; j += i)
                arr[j] = 0;

    for(int i = 2; i <= B; i++)
        if(arr[i])
            primes.push_back(i);
}

int count_primes(int n)
{
    if(dp[n]) return dp[n];

    if(arr[n]) dp[n] = 1;
    else if(!(n & 1)) dp[n] = count_primes(n >> 1) + 1;
    else if(n & 1)
        for(size_t i = 0; i < primes.size(); i++)
            if(!(n % primes[i]))
            {
                dp[n] = count_primes(n / primes[i]) + 1;

                break;
            }

    return dp[n];
}

int main(void)
{
    ios::sync_with_stdio(0);

    int A, B;

    cin >> A >> B;

    eratos(B);

    int answer = 0;

    for(int i = A; i <= B; i++)
        if(arr[count_primes(i)])
            answer++;

    cout << answer;

    return 0;
}