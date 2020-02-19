

int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    if (n == 0) return 0;

    int dp[2];
    dp[0] = -prices[0];
    dp[1] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[1] = dp[1] > (dp[0] + prices[i]) ? dp[1] : (dp[0] + prices[i]);
        dp[0] = dp[0] > -prices[i] ? dp[0] : -prices[i];
    }
    return dp[1];
}