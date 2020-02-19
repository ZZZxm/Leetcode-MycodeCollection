class Solution {
public:
	int longestConsecutive(vector<int>& nums)
	{
		int n = nums.size();
		int ans = 0;
		unordered_set<int> num(nums.begin(), nums.end());//unordered_map��Ϊ��ϣ�����洢

		for (int i = 0; i < n; i++)
		{
			if (num.count(nums[i] - 1) != 0) continue;//���nums[i]�ڼ����У�����Ϊ��߽����������һ�������
			int res = 1, val = nums[i];
			while (num.count(++val) != 0) res++;
			ans = res > ans ? res : ans;
		}
		return ans;
	}
};