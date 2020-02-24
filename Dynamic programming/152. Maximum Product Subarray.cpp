//状态转移方程有点难，要存储max和min

class Solution {
public:
    inline int max(int a, int b, int c)
    {
        int p = a > b ? a : b;
        return c > p ? c : p;
    }

    inline int min(int a, int b, int c)
    {
        int p = a < b ? a : b;
        return c < p ? c : p;
    }

    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        int* maxdp = new int[n + 1];
        int* mindp = new int[n + 1];
        int* dp = new int[n + 1];

        maxdp[0] = 1;
        mindp[0] = 1;
        dp[0] = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            maxdp[i] = max(maxdp[i - 1] * nums[i - 1], mindp[i - 1] * nums[i - 1], nums[i - 1]);
            mindp[i] = min(maxdp[i - 1] * nums[i - 1], mindp[i - 1] * nums[i - 1], nums[i - 1]);
            dp[i] = max(dp[i - 1], maxdp[i]);
        }
        return dp[n];
    }
};