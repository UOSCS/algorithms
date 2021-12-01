#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    bool flag[26] = {false};
    string word = "CAMBRIDGE";

    for(int i = 0; i < word.length(); i++)
        flag[word[i] - 'A'] = true;

    string str;

    cin >> str;

    for(int i = 0; i < str.length(); i++)
        if(!flag[str[i] - 'A'])
            cout << str[i];

    return 0;
}