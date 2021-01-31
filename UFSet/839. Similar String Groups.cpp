#include <UFSet.h>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int size = strs.size();
        UnionFindSet ufset(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isSimilar(strs[i], strs[j]) && ufset.Find(i) != ufset.Find(j))
                {
                    ufset.Union(i, j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            if (ufset.Find(i) == i)
            {
                ans++;
            }
        }
        return ans;
    }

    bool isSimilar(string a, string b)
    {
        int count = 0;
        char p, q;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                count++;
                if (count > 2)
                {
                    return false;
                }

                if (count == 1)
                {
                    p = a[i];
                    q = b[i];
                }

                if (count == 2)
                {
                    if (a[i] != q || b[i] != p)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};