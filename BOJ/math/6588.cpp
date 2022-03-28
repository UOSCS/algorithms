//
//  main.cpp
//  cpp
//
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    cin.tie(0);
        
    bool is_not_prime[1000001] = {false, };
    
    for (int i = 2; i < 1000001; i++)
        if (!is_not_prime[i])
            for (int j = i << 1; j < 1000001; j += i)
                is_not_prime[j] = true;
    
    while (true) {
        
        int n;
        
        cin >> n;
        
        if (!n) break;
        
        int a = 0, b = 0;
        
        for (int i = 3; i <= n >> 1; i++)
            if (!is_not_prime[i] && !is_not_prime[n - i]) {
                a = i;
                b = n - i;
                break;
            }
        
        if (!a && !b)
            cout << "Goldbach's conjecture is wrong.";
        else
            cout << n << " = " << a << " + " << b << '\n';
    }
    
    return 0;
}

