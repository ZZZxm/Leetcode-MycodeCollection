#include <iostream>
#include <vector>
#include <queue>
#include <UFSet.h>

using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {

        int n = grid.size();
        UnionFindSet ufset(n * n);
        queue<int> q;

        int t = 0;
        while (ufset.Find(0) != ufset.Find(n * n - 1))
        {
            t++;
            for (int i = 0; i < n; i++)
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
                int i = q.front() / n;
                int j = q.front() % n;
                q.pop();

                if (i - 1 >= 0 && grid[i - 1][j] <= t && ufset.Find(i * n + j - n) != ufset.Find(0))
                {
                    ufset.Union(0, i * n + j - n);
                    q.push(i * n + j - n);
                }
                if (i + 1 < n && grid[i + 1][j] <= t && ufset.Find(i * n + j + n) != ufset.Find(0))
                {
                    ufset.Union(0, i * n + j + n);
                    q.push(i * n + j + n);
                }
                if (j - 1 >= 0 && grid[i][j - 1] <= t && ufset.Find(i * n + j - 1) != ufset.Find(0))
                {
                    ufset.Union(0, i * n + j - 1);
                    q.push(i * n + j - 1);
                }
                if (j + 1 < n && grid[i][j + 1] <= t && ufset.Find(i * n + j + 1) != ufset.Find(0))
                {
                    ufset.Union(0, i * n + j + 1);
                    q.push(i * n + j + 1);
                }
            }
        }
        return t;
    }
};

int main()
{
    vector<vector<int>> grid;
    vector<int> a, b;
    a.push_back(0);
    a.push_back(1);
    b.push_back(2);
    b.push_back(3);
    grid.push_back(a);
    grid.push_back(b);


    Solution s;
    int ans = s.swimInWater(grid);
    cout << ans;
    return 0;
}