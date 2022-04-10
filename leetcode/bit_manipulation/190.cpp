class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t idx = 0;
        uint32_t answer = 0;
        
        while (idx < 32) {
            answer ^= ((n >> idx) & 1) << (31 - idx);
            
            idx++;
        }
        
        return answer;
    }
};
