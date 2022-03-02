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
    
    string loc_k, loc_r;
    int N;
    
    cin >> loc_k >> loc_r >> N;
    
    string arr[50];
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    for (int i = 0; i < N; i++) {
        
        int len_move = arr[i].length();
        int v_move = 0, h_move = 0;
        
        for (int j = 0; j < len_move; j++)
            switch (arr[i][j]) {
                case 'B':
                    v_move--;
                    break;
                case 'T':
                    v_move++;
                    break;
                case 'L':
                    h_move--;
                    break;
                case 'R':
                    h_move++;
                    break;
                default:
                    break;
            }
        
        if (loc_k[0] + h_move < 'A' || loc_k[0] + h_move > 'H' || loc_k[1] + v_move < '1' || loc_k[1] + v_move > '8')
            continue;
        else if (loc_k[0] + h_move == loc_r[0] && loc_k[1] + v_move == loc_r[1]) {
                if (loc_r[0] + h_move < 'A' || loc_r[0] + h_move > 'H' || loc_r[1] + v_move < '1' || loc_r[1] + v_move > '8')
                    continue;
                else {
                    loc_k[0] += h_move, loc_k[1] += v_move;
                    loc_r[0] += h_move, loc_r[1] += v_move;
                }
        }
        else
            loc_k[0] += h_move, loc_k[1] += v_move;
    }
    
    cout << loc_k << '\n' << loc_r;
    
    return 0;
}
