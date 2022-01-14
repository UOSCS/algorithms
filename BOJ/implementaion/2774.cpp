#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    while(T--)
    {
        string str;

        cin >> str;

        int count = 0;

        bool arr[10] = {false};

        for(int i = 0; i < str.length(); i++)
            if(!arr[str[i] - '0'])
            {
                count++;

                arr[str[i] - '0'] = true;
            }

        cout << count << '\n';
    }

    return 0;
}