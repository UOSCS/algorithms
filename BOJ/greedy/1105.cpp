//
//  main.cpp
//  cpp
//
//  Created by leegwanh on 2022/01/23.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    string L, R;
    
    cin >> L >> R;
    
    int count = 0;
    
    if (L.length() == R.length()) {
        for (int i = 0; i < L.length(); i++) {
            if (L[i] != R[i]) break;
            else if (L[i] == '8') count++;
        }
    }
    
    cout << count << '\n';
    
    return 0;
}

