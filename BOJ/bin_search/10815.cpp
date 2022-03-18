//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    cin.tie(0);
        
    map<int, bool> card;
    
    int N;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int num;
        
        cin >> num;
        
        card[num] = true;
    }
    
    int M;
    
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int num;
        
        cin >> num;
        
        if (card[num])
            cout << 1;
        else
            cout << 0;
        cout << ' ';
    }
    
    return 0;
}

