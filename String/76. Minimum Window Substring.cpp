class Solution {
public:
    bool isSubstring(int hash[])
    {
        for (int i = 0; i < 60; i++) {
            if (hash[i] > 0) return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        int m = s.size(), n = t.size();
        int i, j, ans = m + 1;
        int ansi, ansj;
        int hash[60] = { 0 };
        for (i = 0; i < 60; i++) {
            hash[i] = 0;
        }
        for (i = 0; i < n; i++) {
            hash[t[i] - 'A']++;
        }

        i = 0;
        j = 0;
        while (i < m && j <= m)
        {
            if (j < m) hash[s[j] - 'A']--;
            if (isSubstring(hash)) {
                while (i < m && hash[s[i] - 'A'] < 0) {
                    hash[s[i] - 'A']++;
                    i++;
                }
                if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    ansi = i;
                    ansj = j;
                }
                j++;
            }
            else j++;
        }
        if (ans > m) return "";
        else {
            string res(s, ansi, ansj - ansi + 1);
            return res;
        }
    }
};