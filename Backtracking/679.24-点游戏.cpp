/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool judgePoint24(vector<int> &nums)
    {
        vector<float> vec;
        float temp;
        for (int i = 0; i < nums.size(); i++)
        {
            temp = (float)nums[i];
            vec.push_back(temp);
        }
        return backTracking(vec);
    }

    bool backTracking(vector<float> &nums)
    {
        int size = nums.size();

        if (size == 1)
        {
            return abs(nums[0] - 24) <= 1e-3;
        }

        bool success = false;
        vector<float> copy;
        float temp;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                copy.clear();

                for (int k = 0; k < nums.size(); k++)
                {
                    if (k != i && k != j)
                    {
                        copy.push_back(nums[k]);
                    }
                }

                for (int op = 0; op < 6; op++)
                {
                    temp = calc(nums[i], nums[j], op);
                    copy.push_back(temp);

                    success = backTracking(copy);
                    if (success)
                    {
                        return true;
                    }

                    copy.pop_back();
                }
            }
        }
        return false;
    }

    float calc(float a, float b, int op)
    {
        switch (op)
        {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return b - a;
        case 3:
            return a * b;
        case 4:
            return a / b;
        case 5:
            return b / a;
        }
        return 0;
    }
};
// @lc code=end

int main()
{
    vector<int> vec = {4, 1, 8 ,7};
    Solution s;
    s.judgePoint24(vec);
    return 0;
}
