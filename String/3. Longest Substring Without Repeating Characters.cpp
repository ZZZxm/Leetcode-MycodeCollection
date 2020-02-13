/* 3. 无重复字符的最长字串 */
/* hash */

int lengthOfLongestSubstring(string s)
{
	int hash[300] = { 0 };
	int cur = 0, ans = 0;
	int start = 0;
	int n = s.size();

	for (int i = 0; i < n; i++)
	{
		char ch = s[i];
		if (hash[ch] == 0)
		{
			hash[ch] = i + 1;
			cur++;
			ans = cur > ans ? cur : ans;
		}
		else
		{
			start = hash[ch] > start ? hash[ch] : start;
			hash[ch] = i + 1;
			cur = i + 1 - start;
			ans = cur > ans ? cur : ans;
		}
	}
	return ans;
}