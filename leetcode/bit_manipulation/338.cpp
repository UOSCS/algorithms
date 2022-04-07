class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> answer(n + 1);
        
        answer[0] = 0;
        
        for (int i = 1; i <= n; i++)
            if (i & 1)
                answer[i] = answer[(i - 1) >> 1] + 1;
            else
                answer[i] = answer[i >> 1];
        
        return answer;
    }
};
