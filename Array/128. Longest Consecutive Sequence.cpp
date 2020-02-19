class Solution {
public:
	int longestConsecutive(vector<int>& nums)
	{
		int n = nums.size();
		int ans = 0;
		unordered_set<int> num(nums.begin(), nums.end());//unordered_map作为哈希表来存储

		for (int i = 0; i < n; i++)
		{
			if (num.count(nums[i] - 1) != 0) continue;//如果nums[i]在集合中，以它为左边界的连续序列一定不是最长
			int res = 1, val = nums[i];
			while (num.count(++val) != 0) res++;
			ans = res > ans ? res : ans;
		}
		return ans;
	}
};