bool canChange(string str1, string str2)
{
	//str1 str2都是长度为8的字符串
	int dif = 0;
	for (int i = 0; i < 8; i++)
	{
		if (str1[i] != str2[i]) dif++;
	}

	return dif == 1;
}

int minMutation(string start, string end, vector<string>& bank) 
{
	int n = bank.size();
	int* vis = new int[n];
	for (int i = 0; i < n; i++) vis[i] = 0;

	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (canChange(start, bank[i]))
		{
			vis[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		if (bank[cur] == end) return vis[cur];

		for (int i = 0; i < n; i++)
		{
			if (vis[i]) continue;
			if (canChange(bank[cur], bank[i]))
			{
				vis[i] = vis[cur] + 1;
				q.push(i);
			}
		}
		q.pop();
	}

	return -1;
}