#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    const int MAX_VALUE = 100000;

    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        
        vector<int> ans;

        long sum_a = 0, sum_b = 0;
        int hash_a[100002] = {0}, hash_b[100002] = {0};

        for (int i = 0; i < A.size(); i++) {
            sum_a += A[i];
            hash_a[A[i]]++;
        }
        // O(m)

        for (int i = 0; i < B.size(); i++) {
            sum_b += B[i];
            hash_b[B[i]]++;
        }
        // O(n)

        int delta = sum_a - sum_b;
        int i = 1 + delta / 2, j = 1;
        while (i <= MAX_VALUE && j <= MAX_VALUE)
        {
            if (i < 1) {
                i++;
                j++;
                continue;
            }

            if (hash_a[i] > 0 && hash_b[j] > 0)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }

            i++;
            j++;
        }
        // O(MAX_VALUE)
        return ans;
    }
};