#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int R, C, Q, arr[100] = {0};

    cin >> R >> C >> Q;
    for(int i = 1; i <= R * C; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for(int i = 0; i < Q; i++)
    {
        int r1, c1, r2, c2, width, height, pos, ans = 0;

        cin >> r1 >> c1 >> r2 >> c2;

        width = c2 - c1 + 1;
        height = r2 - r1 + 1;
        pos = (r1 - 1) * C + c1 - 1;
        for(int i = 0; i < height; i++)
        {
            ans += arr[pos + width] - arr[pos];
            pos += C;
        }

        cout << ans / (width * height) << '\n';
    }

    return 0;
}