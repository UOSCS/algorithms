//
//  main.cpp
//  cpp
//
//

#include <iostream>

#define DIVISOR 9901

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    int N;
    
    cin >> N;
    
    int left = 1, right = 1, empty = 1, sum = 3;
    
    while (--N) {
        int left_tmp = left, right_tmp = right, empty_tmp = empty;
        
        left = (right_tmp + empty_tmp) % DIVISOR;
        right = (left_tmp + empty_tmp) % DIVISOR;
        empty = (left_tmp + right_tmp + empty_tmp) % DIVISOR;
        sum  = (left + right + empty) % DIVISOR;
    }
    
    cout << sum;
    
    return 0;
}

