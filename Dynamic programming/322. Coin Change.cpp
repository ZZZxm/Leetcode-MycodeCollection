class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int* dp = new int[amount + 1];
        int n = coins.size();

        dp[0] = 0;
        for (int i = 1; i <= amount; i++) dp[i] = 1000;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] != 1000 ? dp[amount] : -1;
    }
};