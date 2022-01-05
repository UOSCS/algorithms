#include <iostream>
#include <cmath>

#define NUM_OF_ALPHABET 26
#define UPPER_BIAS 32

using namespace std;

bool is_prime(int num)
{
    bool flag = true;

    for(int i = 2; i <= sqrt(num); i++)
        if(!(num % i))
        {
            flag = false;
            
            break;
        }

    return flag;
}

int main(void)
{
    ios::sync_with_stdio(0);

    string str;

    cin >> str;

    int sum = 0;

    for(int i = 0; i < str.length(); i++)
    {
        int num = str[i] - 'a' + 1;

        if(num < 0)
            num += UPPER_BIAS + NUM_OF_ALPHABET;
        
        sum += num;
    }

    if(is_prime(sum))
        cout << "It is a prime word.";
    else
        cout << "It is not a prime word.";

    return 0;
}