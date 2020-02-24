class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();

        int** dp = new int* [m];
        for (int i = 0; i < m; i++) dp[i] = new int[n];

        for (int i = 0; i < m; i++) dp[i][0] = matrix[i][0] - '0';
        for (int j = 0; j < n; j++) dp[0][j] = matrix[0][j] - '0';
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = dp[i][j] > res ? dp[i][j] : res;
            }
        }
        return res * res;
    }
};