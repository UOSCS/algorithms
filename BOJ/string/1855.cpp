#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int K;
    char arr[200][20];
    string str;

    cin >> K >> str;

    int idx = 0;

    for(int i = 0; i < str.length() / K; i++)
    {
        if(i & 1)
            for(int j = K - 1; j >= 0; j--)
                arr[i][j] = str[idx++];
        else
            for(int j = 0; j < K; j++)
                arr[i][j] = str[idx++];
    }

    for(int i = 0; i < K; i++)
        for(int j = 0; j < str.length() / K; j++)
            cout << arr[j][i];
    
    return 0;
}