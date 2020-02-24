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
                cur.assign(s, j, i - j);//s[0...j]�Ѿ��ɲ�֣�����s[j+1...i]�Ƿ�ɲ��
                //j�Ӵ�С���������s[0...i]�ɲ�֣���һ������j,s[j+1...i]���ֵ��е�һ���������
                for (int k = 0; k < n; k++)//�����ֵ�
                {
                    if (cur == wordDict[k]) {
                        dp[i] = true; break;//�Ƿ�ƥ��
                    }
                }
            }
        }
        return dp[s.size()];
    }
};