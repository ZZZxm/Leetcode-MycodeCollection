#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        long dp[101][101];

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0) dp[i][j] = obstacleGrid[i][j - 1] ? 0 : dp[i][j - 1];
                if (j == 0) dp[i][j] = obstacleGrid[i - 1][j] ? 0 : dp[i - 1][j];
                if (i != 0 && j != 0) {
                    if (!obstacleGrid[i - 1][j] && !obstacleGrid[i][j - 1])
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    if (obstacleGrid[i - 1][j] && obstacleGrid[i][j - 1])
                        dp[i][j] = 0;
                    if (obstacleGrid[i - 1][j] && !obstacleGrid[i][j - 1])
                        dp[i][j] = dp[i][j - 1];
                    if (!obstacleGrid[i - 1][j] && obstacleGrid[i][j - 1])
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return obstacleGrid[n - 1][m - 1] ? 0 : dp[n - 1][m - 1];
    }
};