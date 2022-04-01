//
//  main.cpp
//  cpp
//
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    
    cin >> T;
    
    while (T--) {
        int M, N, x, y;
        
        cin >> M >> N >> x >> y;
        
        int n = x;
        bool flag = false;
        int lcm = M * N / gcd(M, N);
        
        while (n <= lcm) {
            int remainder = n % N;
            if (!remainder)
                remainder = N;
            if (remainder == y) {
                flag = true;
                break;
            }
            n += M;
        }
        
        if (flag)
            cout << n << '\n';
        else
            cout << -1 << '\n';
    }
    
    return 0;
}

