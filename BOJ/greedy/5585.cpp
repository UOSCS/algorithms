#include <iostream>

using namespace std;

int main(void)
{
    int price, change, count = 0;
    int arr[] = {500, 100, 50, 10, 5, 1};

    cin >> price;
    change = 1000 - price;

    for(int i = 0; i < 6; i++)
    {
        count += change / arr[i];
        change %= arr[i];
        if(!change)
            break;
    }

    cout << count << '\n';

    return 0;
}