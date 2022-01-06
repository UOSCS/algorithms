#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, L;

    cin >> N >> L;

    int num = 1, count = 0;

    while(true)
    {
        string str_num = to_string(num);

        bool flag = true;

        for(int i = 0; i < str_num.length(); i++)
            if(str_num[i] == L + '0')
            {
                flag = false;

                break;
            }

        if(flag) count++;

        if(count == N) break;
        
        num++;
    }

    cout << num;

    return 0;
}