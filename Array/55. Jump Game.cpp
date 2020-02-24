//贪心算法最快

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while (i < n - 1)
        {
            int j, max = 0;
            int next = i;
            for (j = 1; j <= nums[i] && i + j < n; j++) {
                if (i + j + nums[i + j] > max) {
                    next = i + j;
                    max = i + j + nums[i + j];
                }
            }
            if (i == next) return false;
            i = next;
        }
        return true;
    }
};