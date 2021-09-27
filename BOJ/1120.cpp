#include <iostream>

using namespace std;

int count_diff(string a, string b)
{
    int ret = 0;

    for(size_t i = 0; i < a.length(); i++)
        if(a[i] != b[i])
            ret++;

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);

    string A, B;

    cin >> A >> B;

    int answer = 50;

    if(A.length() == B.length())
        answer = count_diff(A, B);
    else
        for(size_t i = 0; i <= B.length() - A.length(); i++)
            answer = min(answer, count_diff(A, B.substr(i, A.length())));
    
    cout << answer;

    return 0;
}