#include <iostream>

using namespace std;

void make_min(string &str)
{
    for(int i = 0; i < str.length(); i++)
        if(str[i] == '6')
            str[i] = '5';
}

void make_max(string &str)
{
    for(int i = 0; i < str.length(); i++)
        if(str[i] == '5')
            str[i] = '6';
}

int main(void)
{
    ios::sync_with_stdio(0);

    string A, B;

    cin >> A >> B;

    make_min(A), make_min(B);

    cout << stoi(A) + stoi(B) << ' ';

    make_max(A), make_max(B);

    cout << stoi(A) + stoi(B);

    return 0;
}