#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int D, H, W;

    cin >> D >> H >> W;

    int D_square = D * D;
    int divisor = H * H + W * W;
    int height = sqrt(D_square * H * H / divisor);
    int width = sqrt(D_square * W * W / divisor);

    cout << height << ' ' << width;

    return 0;
}