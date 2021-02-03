/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class MedianHeap
{
public:
    MedianHeap(vector<int> &vec)
    {
        vector<int> v(vec);
        sort(v.begin(), v.end());

        int k = (v.size() - 1) / 2;
        for (int i = 0; i <= k; i++)
        {
            smaller.push(v[i]);
            small_size++;
        }
            
        for (int i = k + 1; i < v.size(); i++)
        {
            larger.push(v[i]);
            large_size++;
        }
            
    }

    void insert(int val)
    {
        if (smaller.empty() || val <= smaller.top())
        {
            smaller.push(val);
            small_size++;
        }
        else
        {
            larger.push(val);
            large_size++;
        }
        get_balance();
    }

    void erase(int val)
    {
        if (delay_delete.count(val) == 0)
        {
            delay_delete.insert(make_pair(val, 1));
        }
        else
        {
            delay_delete[val]++;
        }
        

        if (val <= smaller.top())
        {
            small_size--;
            if (val == smaller.top())
            {
                clip();
            }
        }
        else
        {
            large_size--;
            if (val == larger.top())
            {
                clip();
            }
        }
        get_balance();
    }

    double get_median()
    {
        if (small_size > large_size)
        {
            return smaller.top();
        }
        else
        {
            return ((double)smaller.top() + (double)larger.top()) / 2;
        }
    }

private:
    priority_queue<int> smaller;

    priority_queue<int, vector<int>, greater<int>> larger;

    unordered_map<int, int> delay_delete;

    int small_size = 0;

    int large_size = 0;

    void get_balance()
    {
        if (small_size - large_size > 1)
        {
            larger.push(smaller.top());
            smaller.pop();
            large_size++;
            small_size--;
            clip();
        }
        if (large_size > small_size)
        {
            smaller.push(larger.top());
            larger.pop();
            large_size--;
            small_size++;
            clip();
        }
    }

    void clip()
    {
        while (!smaller.empty() && delay_delete.count(smaller.top()) != 0)
        {
            if (delay_delete[smaller.top()] > 0)
            {
                delay_delete[smaller.top()]--;
                smaller.pop();
            }
            else
            {
                break;
            }
            
        }

        while (!larger.empty() && delay_delete.count(larger.top()) != 0)
        {
            if (delay_delete[larger.top()] > 0)
            {
                delay_delete[larger.top()]--;
                larger.pop();
            }
            else
            {
                break;
            }
            
        }
    }
};

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> vec(nums.begin(), nums.begin() + k);
        MedianHeap mh(vec);
        vector<double> ans;

        for (int j = k; j < nums.size(); j++)
        {
            ans.push_back(mh.get_median());
            mh.erase(nums[j - k]);
            mh.insert(nums[j]);
        }
        ans.push_back(mh.get_median());
        return ans;
    }
};



// @lc code=end
