#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;

    cin >> T;

    while(T--)
    {
        int N;

        cin >> N;

        int count = 0;

        for(int i = 2; i <= N; i++)
        {
            int tmp = N;

            while(tmp)
            {
                if(!(tmp % i)) count++;
                else break;

                tmp /= i;
            }
        }

        cout << count << '\n';
    }

    return 0;
}