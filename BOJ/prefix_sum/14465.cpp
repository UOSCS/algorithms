#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, K, B;
    bool arr[100001] = {false};

    cin >> N >> K >> B;
    for(int i = 0, tmp; i < B; i++)
    {
        cin >> tmp;
        arr[tmp] = true;
    }

    int low = 1, high = K, cnt = 0;
    for(int i = low; i <= high; i++)
        cnt += arr[i];

    int tmp = cnt;
    while(high < N)
    {
        tmp -= arr[low++];
        tmp += arr[++high];
        cnt = min(cnt, tmp);
    }

    cout << cnt;

    return 0;
}
