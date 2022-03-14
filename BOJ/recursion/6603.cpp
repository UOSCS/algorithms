//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <vector>

using namespace std;

int k;

void lotto(int arr[], int n, int seq, vector<int> &v) {
    if (seq == 6) {
        for (int i : v)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    if (n >= k)
        return;
    
    v.push_back(arr[n]);
    lotto(arr, n + 1, seq + 1, v);
    v.pop_back();
    lotto(arr, n + 1, seq, v);
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
        
    while (true) {
        cin >> k;
        
        if (!k)
            break;
        
        int arr[12];
        
        for (int i = 0; i < k; i++)
            cin >> arr[i];
        
        vector<int> v;
        
        lotto(arr, 0, 0, v);
        
        cout << '\n';
    }
    
    return 0;
}

