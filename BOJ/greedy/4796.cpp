#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int i = 1; 

    while(true)
    {
        int L, P, V;

        cin >> L >> P >> V;

        if(!L && !P && !V)
            break;

        int total = 0;

        while(true)
        {
            if(V - P >= 0)
            {
                total += L;
                V -= P;
            }
            else
            {
                total += min(V, L);
                break;
            }
        }

        cout << "Case " << i << ": " << total << '\n';

        i++;
    }

    return 0;
}