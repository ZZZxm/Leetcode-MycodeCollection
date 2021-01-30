#include <iostream>
#include <vector>
#include <queue>
#include <UFSet.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        UnionFindSet ufset(m * n);

        queue<int> q;

        int ans = 0;
        while (ufset.Find(0) != ufset.Find(m * n - 1))
        {
            ans++;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (ufset.Find(i * n + j) == ufset.Find(0))
                    {
                        q.push(i * n + j);
                    }
                }
            }

            while (!q.empty())
            {
                int i = q.front() / m;
                int j = q.front() % m;
                int h = heights[i][j];
                q.pop();

                if (i - 1 >= 0 && abs(heights[i - 1][j] - h) <= ans && ufset.Find(i * n + j - n) != ufset.Find(0))
                {
                    ufset.Union(0, i * n + j - n);
                    q.push(i * n + j - n);
                }
                if (i + 1 < n && abs(heights[i + 1][j] - h) <= ans && ufset.Find(i * n + j + n) != ufset.Find(0))
                {
                    ufset.Union(0, i * n + j + n);
                    q.push(i * n + j + n);
                }
                if (j - 1 >= 0 && abs(heights[i][j - 1] - h) <= ans && ufset.Find(i * n + j - 1) != ufset.Find(0))
                {
                    ufset.Union(0, i * n + j - 1);
                    q.push(i * n + j - 1);
                }
                if (j + 1 < n && abs(heights[i][j + 1] - h) <= ans && ufset.Find(i * n + j + 1) != ufset.Find(0))
                {
                    ufset.Union(0, i * n + j + 1);
                    q.push(i * n + j + 1);
                }
            }
        }
        return ans;
    }
};