#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    while(T--)
    {
        int N;

        cin >> N;

        int square_N = N * N;
        string sqaure_N_str = to_string(square_N);
        string N_str = to_string(N);

        if(N_str == sqaure_N_str.substr(sqaure_N_str.length() - N_str.length(), N_str.length()))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}