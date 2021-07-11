#include <iostream>
#include <map>

using namespace std;

int A[1000], B[1000];

void input(int length, int arr[])
{
    for(int i = 0; i < length; i++)
        cin >> arr[i];
}

void pre_process(int length, int arr[], map<int, int> &m)
{
    for(int i = 0; i < length; i++)
    {
        int sum = 0;
        int j = i;
        while(!i || (j + 1) % length != i)
        {
            m[sum += arr[j]]++;
            if(i && j == length - 1)
                j = 0;
            else
                if(j == length - 1)
                    break;
                else
                    j++;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    int size, m, n, ans = 0;
    map<int, int> A_m, B_m;

    cin >> size >> m >> n;
    input(m, A); input(n, B);

    pre_process(m, A, A_m); pre_process(n, B, B_m);
    for(int i = 1; i < size; i++)
        ans += A_m[i] * B_m[size - i];
    ans += A_m[size] + B_m[size];

    cout << ans;

    return 0;
}