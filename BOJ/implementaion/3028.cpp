#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string str;

    cin >> str;

    bool arr[3] = {true,};

    for(int i = 0; i < str.length(); i++)
        if(str[i] == 'A') swap(arr[0], arr[1]);
        else if(str[i] == 'B') swap(arr[1], arr[2]);
        else swap(arr[0], arr[2]);

    for(int i = 0; i < 3; i++)
        if(arr[i])
            cout << i + 1;

    return 0;
}