/* 98 验证二叉搜索树 */
/* 题目不难，边界情况比较麻烦，AC时我用了minborder和maxborder两个指示变量实现，用long应该会方便一点 */
/* 空间复杂度待提高 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ValRange {
    TreeNode* node;
    int minval;
    int maxval;
    bool minborder = 0;
    bool maxborder = 0;
    ValRange(TreeNode* p, int min, int max)
        :node(p), minval(min), maxval(max) {};
    ValRange(TreeNode* p, int min, int max, bool minb, bool maxb)
        :node(p), minval(min), maxval(max), minborder(minb), maxborder(maxb) {};
};

/* To judge if a tree is a valid binary search tree.*/
bool isValidBST(TreeNode* root) 
{
    queue<ValRange> q;
    ValRange v(root, INT_MIN, INT_MAX);
    q.push(v);

    while (!q.empty())
    {
        ValRange cur = q.front();
        TreeNode* temp = cur.node;
        bool have_min = cur.minborder, have_max = cur.maxborder;

        if (temp == NULL) return true;
        if (temp->val <= cur.minval)
        {
            if (temp->val != INT_MIN || cur.minborder) return false;
        }
        if (temp->val >= cur.maxval)
        {
            if (temp->val != INT_MAX || cur.maxborder) return false;
        }
        if (temp->left != NULL)
        {
            ValRange lnode(temp->left, cur.minval, temp->val, have_min, 1);
            q.push(lnode);
        }
        if (temp->right != NULL)
        {
            ValRange rnode(temp->right, temp->val, cur.maxval, 1, have_max);
            q.push(rnode);
        }
        q.pop();
    }
    return true;
}