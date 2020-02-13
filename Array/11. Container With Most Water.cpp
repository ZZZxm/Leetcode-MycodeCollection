/*˫ָ�뷨*/

int maxArea(vector<int>& height)
{
    int ans = 0;
    int n = height.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        int h = height[i] < height[j] ? height[i] : height[j];
        int cur = (j - i) * h;
        ans = ans < cur ? cur : ans;

        if (height[i] < height[j])
        {
            int a = height[i];
            while (i < n && height[i] <= a) i++;
        }
        else
        {
            int a = height[j];
            while (j >= 0 && height[j] <= a) j--;
        }
    }
    return ans;
}