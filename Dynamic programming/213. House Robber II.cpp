class Solution {
public:

	int rob(vector<int>& nums)
	{
		int n = nums.size();
		if (n == 0) return 0;
		if (n == 1) return nums[0];

		int** dp = new int* [n + 4];
		for (int i = 1; i <= n + 3; i++) dp[i] = new int[4];
		//dp[0]为打劫了第一个和最后一个，dp[1]为打劫了第一个但未打劫最后一个
		//dp[2]为打劫了最后一个但未打劫第一个，dp[3]为第一个和最后一个都未打劫

		dp[1][0] = nums[0]; dp[1][1] = -1; dp[1][2] = -1; dp[1][3] = 0;
		int ma = max(nums[0], nums[1]);
		dp[2][0] = -1; dp[2][1] = nums[0]; dp[2][2] = nums[1]; dp[2][3] = 0;

		for (int i = 3; i < n; i++)
		{
			dp[i][0] = dp[i - 1][1] + nums[i - 1];
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][2] = dp[i - 1][3] + nums[i - 1];
			dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]);
		}
		return max(max(dp[n - 1][0], dp[n - 1][1]), max(dp[n - 1][2], dp[n - 1][3] + nums[n - 1]));
	}
};