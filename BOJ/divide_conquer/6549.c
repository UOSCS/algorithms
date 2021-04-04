#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll max(ll a, ll b)
{
    return a > b ? a : b;
}

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

ll solve(int *arr, int left, int right)
{
    if(left == right)
        return arr[left];
    int mid = (left + right) / 2;
    ll ret = max(solve(arr, left, mid), solve(arr, mid + 1, right));
    int low = mid;
    int high = mid + 1;
    int height = min(arr[low], arr[high]);
    ret = max(ret, height * 2);
    while(left < low || high < right)
    {
        if(high < right && (low == left || arr[low - 1] < arr[high + 1]))
            height = min(height, arr[++high]);
        else
            height = min(height, arr[--low]);
        ret = max(ret, (high - low + 1) * (ll)height);
    }
    return ret;
}

int main(void)
{
    while(1)
    {
        int n, *arr;
        scanf("%d", &n);
        if(!n)
            break;
        arr = malloc(sizeof(int) * n);
        for(int i = 0; i < n; i++)
            scanf("%d", arr + i);

        printf("%lld\n", solve(arr, 0, n - 1));

        free(arr);
    }
    
    return 0;
}