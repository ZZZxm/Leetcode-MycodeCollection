/* 49. Group Anagrams */
// suppose there are N strings, length of the longest string is K 

/* Solution 1 : Hash */
bool isAnagrams(int* hash1, int* hash2)
{
	for (int i = 0; i < 26; i++)
	{
		if (hash1[i] != hash2[i]) return false;
	}
	return true;
}//O(26)

void initHash(int* hash, string& str)
{
	for (int i = 0; i < 26; i++) hash[i] = 0;

	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		hash[*it - 'a']++;
	}
}//O(K)


vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> ans;

	int n = strs.size();
	bool* vis = new bool[n];// to show has the string been visited
	for (int i = 0; i < n; i++) vis[i] = false;

	int** hash = new int* [n];
	for (int i = 0; i < n; i++) {
		hash[i] = new int[26];
		initHash(hash[i], strs[i]);//O(K)
	}//O(N*K)

	for (int i = 0; i < n; i++)
	{
		if (vis[i]) continue;
		vector<string> cur;
		cur.push_back(strs[i]);
		for (int j = i + 1; j < n; j++) {
			if (vis[j]) continue;
			if (isAnagrams(hash[i], hash[j])) {//O(26)
				cur.push_back(strs[j]);
				vis[j] = true;
			}
		}
		ans.push_back(cur);
	}//O(N*26)

	for (int i = 0; i < n; i++) {
		delete[] hash[i];
	}//O(N)
	delete[] hash;
	delete[] vis;

	return ans;
}

/* Solution 2: Sort, map*/
// 学习：unordered_map:在用map时，如果不需要map进行排序，用unordered_map会更快
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> res;
	map<string, vector<string>> ma;
	string tmp;

	for (vector<string>::iterator it = strs.begin(); it != strs.end(); it++)
	{
		string str = *it;
		tmp = str;
		sort(tmp.begin(), tmp.end());
		ma[tmp].push_back(str);
	}
	for (map<string, vector<string>>::iterator it = ma.begin; it != ma.end(); it++)
	{
		res.push_back((*it).second);
	}
	return res;
}