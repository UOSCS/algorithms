#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    
    string N, F;

    cin >> N >> F;

    N = to_string(stoi(N) - stoi(N) % 100);

    int remainder = stoi(N) % stoi(F);

    if(remainder)
        N = to_string(stoi(F) * ((stoi(N) / stoi(F)) + 1));
    
    cout << *(N.rbegin() + 1) << *N.rbegin();

    return 0;
}