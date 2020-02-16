class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start;
        int ans = 0, cur;
        for (int i = 0; i < n; i++)//ÆæÊı
        {
            cur = 1;
            int j = 1;
            while (i - j >= 0 && i + j < n)
            {
                if (s[i - j] == s[i + j]) cur += 2;
                else break;
                j++;
            }
            if (cur > ans)
            {
                ans = cur;
                start = i - j + 1;
            }
        }

        for (int i = 0; i < n - 1; i++)//Å¼Êı
        {
            if (s[i] != s[i + 1]) continue;
            cur = 2;
            int j = 1;
            while (i - j >= 0 && i + 1 + j < n)
            {
                if (s[i - j] == s[i + j + 1]) cur += 2;
                else break;
                j++;
            }
            if (cur > ans)
            {
                ans = cur;
                start = i - j + 1;
            }
        }

        string res(s, start, ans);
        return res;
    }
};