#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[300];
vector<int> v;

bool available(int n)
{
    int sum = 0, count = 0;

    for(int i = 0; i < N; i++)
    {
        if(arr[i] > n)
            return false;
        else if(arr[i] + sum <= n)
            sum += arr[i];
        else
        {
            count++;
            sum = arr[i];
        }
    }

    return count < M;
}

int divide(int n)
{
    int sum = 0, count = 0, group = 1;

    for(int i = 0; i < N; i++)
    {
        if(arr[i] + sum <= n)
        {
            count++;
            sum += arr[i];
        }
        else
        {
            v.push_back(count);
            group++;
            sum = arr[i];
            count = 1;
        }
    }
    v.push_back(count);

    return group;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int l, r, g, idx;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    l = 1; r = N * 100;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(available(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    g = divide(l); idx = v.size() - 1;
    while(g < M)
    {
        if(v[idx] == 1)
            idx--;
        else
        {
            v[idx]--;
            v.push_back(1);
            g++;
        }
    }

    cout << l << '\n';
    for(int c : v)
        cout << c << ' ';

    return 0;
}