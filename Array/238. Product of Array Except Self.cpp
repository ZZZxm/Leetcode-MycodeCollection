/* 238 除自身以外数组的乘积 */
/* 时间复杂度O(n),空间复杂度O(1) */

/* 不能使用除法*/

vector<int> productExceptSelf(vector<int>& nums) 
{
	vector<int> output;//vector which will be returned

	int n = nums.size();

	for (int i = 0; i < n; i++) {
		output.push_back(1);
	}// initialize array left and right

	int pro = 1;
	for (int i = 0; i < n; i++)
	{
		output[i] *= pro;
		pro *= nums[i];
	}//calculate array left
	pro = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		output[i] *= pro;
		pro *= nums[i];
	}//calculate array right

	return output;
}