/* 42 接雨水 */
/* The same solution of problem above.(array left and array right) */
/* Other solution: stack, double pointer */

inline int max(int a, int b)
{
	return a >= b ? a : b;
}

inline int min(int a, int b)
{
	return a <= b ? a : b;
}

int trap(vector<int>& height) 
{
	int ans = 0;
	int n = height.size();
	int* left = new int[n], * right = new int[n];

	int lmax = 0, rmax = 0;
	for (int i = 0; i < n; i++)
	{
		left[i] = lmax;
		lmax = max(lmax, height[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		right[i] = rmax;
		rmax = max(rmax, height[i]);
	}
	for (int i = 0; i < n; i++)
	{
		int h = min(left[i], right[i]);
		if (h > height[i])
		{
			ans += (h - height[i]);
		}
	}
	return ans;
}