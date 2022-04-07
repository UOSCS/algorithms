class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX = 10000;
        int current_coin = coins[0];
        int dp[10001];
        
        fill(dp + 1, dp + amount + 1, MAX);
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); i++)
            for (int j = 1; j <= amount; j++)
                if (j >= coins[i])
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        
        return dp[amount] == MAX ? -1 : dp[amount];
    }
};
