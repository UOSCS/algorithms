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
        
    int E, S, M;
    
    cin >> E >> S >> M;
    
    int i = 1;
    while (true) {
        if (!((i - E) % 15) && !((i - S) % 28) && !((i - M) % 19)) {
            cout << i;
            break;
        }
        i++;
    }
    
    return 0;
}

