#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int count = 0;

    for(int i = 0; i < 8; i++)
    {
        int white = i % 2;

        for(int j = 0; j < 8; j++)
        {
            char tmp;

            cin >> tmp;

            if(j % 2 == white && tmp == 'F')
                count++;
        }
    }

    cout << count;

    return 0;
}