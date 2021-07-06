#include <iostream>
#include <map>

using namespace std;

void get_prefix_sum(map<int, int> &m, int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            m[sum]++;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    map<int, int> A_m, B_m;
    int T, n, m, A[1000], B[1000];
    long ans;

    cin >> T >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> B[i];

    get_prefix_sum(A_m, A, n);
    get_prefix_sum(B_m, B, m);
    for(auto i : A_m)
        ans += (long)i.second * B_m[T - i.first];

    cout << ans;

    return 0;
}