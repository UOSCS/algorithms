//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <cmath>

using namespace std;

int calc(int N, int r, int c)
{
    if (!N) return 0;
        
    int v_bias = 0, h_bias = 0;
    int standard = 1 << (N - 1);
    int answer = 0;
    
    if (r >= standard) v_bias++;
    if (c >= standard) h_bias++;
    
    answer += ((v_bias << 1) + h_bias) * pow(1 << (N - 1), 2);
    
    if (v_bias) r -= standard;
    if (h_bias) c -= standard;
    N--;
    
    return answer + calc(N, r, c);
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    int N, r, c;
    
    cin >> N >> r >> c;
    
    cout << calc(N, r, c);
}

