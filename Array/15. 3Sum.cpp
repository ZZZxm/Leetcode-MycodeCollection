

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> ans;

	vector<int> pos_vec, neg_vec;//区分正数负数
	set<int> pos_set, neg_set;
	int have_zero = 0;

	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		if (*it > 0) {
			pos_vec.push_back(*it);
			pos_set.insert(*it);
		}
		if (*it < 0) {
			neg_vec.push_back(*it);
			neg_set.insert(*it);
		}
		if (*it == 0) have_zero++;
	}//initial vector and set for positive and negative number, O(n)

	sort(pos_vec.begin(), pos_vec.end());
	sort(neg_vec.begin(), neg_vec.end());
	// sort, O(nlogn)

	for (set<int>::iterator it = pos_set.begin(); it != pos_set.end(); it++)
	{
		int sum = -(*it);
		int n = neg_vec.size();
		int i, j = n - 1;
		for (i = 0; i < n; i++)
		{
			if (neg_vec[i] > sum) break;
		}

		while (i < j)
		{
			int a = neg_vec[i], b = neg_vec[j];
			if (a + b == sum)
			{
				vector<int> cur;
				cur.push_back(a); cur.push_back(b); cur.push_back(-sum);
				ans.push_back(cur);//push back to answer
				while (i < n - 1 && neg_vec[i] == neg_vec[i + 1]) i++;
				if (i < j) i++;
			}
			if (a + b < sum)
			{
				while (i < n - 1 && neg_vec[i] == neg_vec[i + 1]) i++;
				if (i < j) i++;
			}
			if (a + b > sum)
			{
				while (j > 0 && neg_vec[j] == neg_vec[j - 1]) j--;
				if (i < j) j--;
			}
		}
	}// one positve and two negative

	for (set<int>::iterator it = neg_set.begin(); it != neg_set.end(); it++)
	{
		int sum = -(*it);
		int n = pos_vec.size();
		int i = 0, j;
		for (j = 0; j < n; j++)
		{
			if (pos_vec[j] >= sum) break;
		}
		j--;

		while (i < j)
		{
			int a = pos_vec[i], b = pos_vec[j];
			if (a + b == sum)
			{
				vector<int> cur;
				cur.push_back(a); cur.push_back(b); cur.push_back(-sum);
				ans.push_back(cur);//push back to answer
				while (i < n - 1 && pos_vec[i] == pos_vec[i + 1]) i++;
				if (i < j) i++;
			}
			if (a + b < sum)
			{
				while (i < n - 1 && pos_vec[i] == pos_vec[i + 1]) i++;
				if (i < j) i++;
			}
			if (a + b > sum)
			{
				while (j > 0 && pos_vec[j] == pos_vec[j - 1]) j--;
				if (i < j) j--;
			}
		}
	}// two positve and one negative

	if (have_zero)//have zero
	{
		int m = pos_vec.size(), n = neg_vec.size();
		int i = 0, j = n - 1;

		while (i < m && j >= 0)
		{
			int a = pos_vec[i], b = neg_vec[j];
			if (a + b == 0)
			{
				vector<int> cur;
				cur.push_back(a); cur.push_back(b); cur.push_back(0);
				ans.push_back(cur);//push back to answer

				while (i < m - 1 && pos_vec[i] == pos_vec[i + 1]) i++;
				i++;
				while (j > 0 && neg_vec[j] == neg_vec[j - 1]) j--;
				j--;
			}
			if (a + b < 0) i++;
			if (a + b > 0) j--;
		}
	}// one positve, one negative and a zero
	if (have_zero >= 3)
	{
		vector<int> cur;
		cur.push_back(0); cur.push_back(0); cur.push_back(0);
		ans.push_back(cur);
		//special 0+0+0=0
	}
	return ans;
}