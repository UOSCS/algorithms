#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int M, pos_ball = 1;

    cin >> M;

    while(M--)
    {
        int a, b;

        cin >> a >> b;

        if(a == pos_ball || b == pos_ball)
            if(a == pos_ball) pos_ball = b;
            else pos_ball = a;
    }

    cout << pos_ball;

    return 0;
}