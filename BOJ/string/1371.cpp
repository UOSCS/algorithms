#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int arr[26] = {0};

    while(!cin.eof())
    {
        string s;

        getline(cin, s);

        for(int i = 0; i < s.size(); i++)
            arr[s[i] - 'a']++;
    }

    int max_value = *max_element(arr, arr + 26);

    for(int i = 0; i < 26; i++)
        if(arr[i] == max_value)
            cout << (char) (i + 'a');

    return 0;

}