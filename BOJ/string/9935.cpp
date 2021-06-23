#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string str, bomb, result = "";

    cin >> str >> bomb;

    for(int i = 0; i < str.length(); i++)
    {
        result.push_back(str[i]);
        if(result.back() == bomb.back())
        {
            if(result.size() >= bomb.size())
            {
                int count = 0;
                for(int i = 1; i <= bomb.size(); i++)
                    if(result[result.size() - i] == bomb[bomb.size() - i])
                        count++;
                    else
                        break;
                if(bomb.size() == count)
                    for(int i = 0; i < count; i++)
                        result.pop_back();
            }
        }
    }

    if(result.size())
        cout << result;
    else
        cout << "FRULA";

    return 0;
}