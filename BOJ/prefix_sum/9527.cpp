#include <iostream>

using namespace std;

long calculate_number_of_1(long number)
{
    long number_of_1 = 0L, current_bit = 1L;

    while(current_bit <= number)
    {
        if(number & current_bit)
            number_of_1 += ((number - number % (current_bit << 1)) >> 1) + number % current_bit;
        else
            number_of_1 += (number - number % current_bit) >> 1;

        current_bit <<= 1;
    }

    return number_of_1;
}

int main(void)
{
    ios::sync_with_stdio(0);

    long A, B;

    cin >> A >> B;

    cout << calculate_number_of_1(B + 1) - calculate_number_of_1(A);

    return 0;
}
