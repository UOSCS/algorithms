#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int count = 0;
    string document, word;

    getline(cin, document), getline(cin, word);

    for(int i = 0; i < document.size(); i++)
    {
        bool flag = true;
        for(int j = 0; j < word.size(); j++)
            if(document[i + j] != word[j])
            {
                flag = false;
                break;
            }
        if(flag)
        {
            count++;
            i += word.size() - 1;
        }
    }

    cout << count;

    return 0;
}