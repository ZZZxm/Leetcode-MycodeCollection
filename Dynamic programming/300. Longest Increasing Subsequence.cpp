
//dp O(n^2)
//最优解O(nlogn) 二分法 太难了！！！
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) return 0;

        int* dp = new int[n + 1];

        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 1;
            for (int j = 1; j < i; j++)
            {
                if (nums[i - 1] > nums[j - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = 1;
        for (int i = 2; i <= n; i++) res = max(res, dp[i]);
        return res;
    }
};