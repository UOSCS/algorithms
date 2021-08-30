#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string S;
    int num_of_flip_0 = 0, num_of_flip_1 = 0;

    cin >> S;

    int prev;

    for(size_t i = 0; i < S.size(); i++)
    {
        if(!i)
            prev = S[i];

        if(i && prev == S[i])
            continue;

        if(S[i] == '1')
            num_of_flip_1++;
        else
            num_of_flip_0++;
        
        prev = S[i];
    }

    cout << min(num_of_flip_0, num_of_flip_1);

    return 0;
}