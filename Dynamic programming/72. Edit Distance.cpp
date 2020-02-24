//2020.2.19
//dp�ĵ�������

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        //base case
        //dp[i][0]��ʾword2������ɣ�ֻ��ɾ��i���ַ�����
        //dp[0][j]��ʾword1������ɣ�ֻ�����j���ַ�����

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    //dp[i - 1][j]����word1��ɾ���ַ�word1[i-1]
                    //dp[i][j - 1]����word1�в����ַ�word2[j-1]
                    //dp[i - 1][j - 1]����word1[i-1]�滻��word2[j-1]
                }
            }
        }
        return dp[m][n];
    }
};