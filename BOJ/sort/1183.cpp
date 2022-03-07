//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);

    int N;
    
    cin >> N;
    
    int A[50], B[50];
    
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];
    
    if (N & 1) cout << 1;
    else {
        int arr[50];
        for (int i = 0; i < N; i++)
            arr[i] = B[i] - A[i];
        sort(arr, arr + N);
        cout << arr[N >> 1] - arr[(N >> 1) - 1] + 1;
    }
    
    return 0;
}

