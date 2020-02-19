/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int find(vector<int>& vec, int val)
    {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == val) return i + 1;
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size() == 0) return NULL;

        int val = preorder[0];
        TreeNode* root = new TreeNode(val);//当前树结点
        if (preorder.size() == 1) return root;

        int i = find(inorder, val), j;

        vector<int> leftpre, leftin;
        vector<int> rightpre, rightin;
        vector<int>::iterator it1, it2;
        if (i == 1) {
            root->left = buildTree(leftpre, leftin);
        }
        else {
            it1 = preorder.begin(); it1++;
            it2 = preorder.begin();
            j = i;
            while (j--) it2++;
            leftpre.assign(it1, it2);

            it1 = inorder.begin();
            it2 = inorder.begin();
            j = i - 1;
            while (j--) it2++;
            leftin.assign(it1, it2);
            root->left = buildTree(leftpre, leftin);
        }

        if (i == preorder.size()) {
            root->right - buildTree(rightpre, rightin);
        }
        else {
            it1 = preorder.begin();
            j = i;
            while (j--) it1++;
            rightpre.assign(it1, preorder.end());

            it1 = inorder.begin();
            j = i;
            while (j--) it1++;
            rightin.assign(it1, inorder.end());
            root->right = buildTree(rightpre, rightin);
        }

        return root;
    }
};