class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = wordDict.size();
        bool* dp = new bool[s.size() + 1];
        for (int i = 1; i <= s.size(); i++) dp[i] = false;

        string cur;

        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] == false) continue;
                if (dp[i] == true) break;
                cur.assign(s, j, i - j);//s[0...j]已经可拆分，计算s[j+1...i]是否可拆分
                //j从大到小遍历，如果s[0...i]可拆分，则一定存在j,s[j+1...i]与字典中的一个单词相等
                for (int k = 0; k < n; k++)//遍历字典
                {
                    if (cur == wordDict[k]) {
                        dp[i] = true; break;//是否匹配
                    }
                }
            }
        }
        return dp[s.size()];
    }
};