class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		size = digits.size();//digits的长度

		if (size == 0) return ans;//输入为空

		int j = digits[0] - '2';
		for (int k = 0; k < 4; k++)
		{
			if (num[j][k] == '\u0000') break;
			string str;
			str += num[j][k];
			dfs(digits, str, 1);
		}

		return ans;
	}

private:
	void dfs(string digits, string str, int i)
	{
		if (i == size)
		{
			ans.push_back(str);
			return;
		}

		int j = digits[i] - '2';
		for (int k = 0; k < 4; k++)
		{
			if (num[j][k] == '\u0000') break;
			string cur = str;
			cur += num[j][k];
			dfs(digits, cur, i + 1);
		}
	}

	vector<string> ans;
	int size;
	char num[8][4] = { {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'}
					  ,{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'} };
	//输入数字对应字母
};