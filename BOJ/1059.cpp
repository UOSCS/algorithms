#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int L, my_set[50], n;

    cin >> L;
    for(int i = 0; i < L; i++)
        cin >> my_set[i];
    cin >> n;

    sort(my_set, my_set + L);

    int low, high;

    for(int i = 0; i < L; i++)
    {
        if(n > my_set[i] && n < my_set[i + 1])
        {
            low = my_set[i], high = my_set[i + 1];

            break;
        }
        
        if(n == my_set[i])
        {
            low = high = 0;

            break;
        }

        if(i == L - 1)
            low = 0, high = my_set[0];
    }

    int count = 0;

    for(int i = low + 1; i <= n; i++)
        for(int j = n; j < high; j++)
            if(i != j)
                count++;

    cout << count;

    return 0;
}