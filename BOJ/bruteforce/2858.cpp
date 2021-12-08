#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int R, B;

    cin >> R >> B;

    for(int i = 1; i <= sqrt(B); i++)
        if(!(B % i))
        {
            int w = i + 2, h = B / i + 2;

            if(((w + h) << 1) - 4 == R)
            {
                if(w < h)
                    swap(w, h);
                
                cout << w << ' ' << h;
            }
        }

    return 0;
}