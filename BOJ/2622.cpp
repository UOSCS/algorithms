#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    int count = 0;

    for(int a = 1; a <= N >> 1; a++)
    {
        for(int b = a; b <= N >> 1; b++)
        {
            int c = N - (a + b);

            if(c < b) break;

            if(a + b > c) count++;
        }
    }

    cout << count;

    return 0;
}