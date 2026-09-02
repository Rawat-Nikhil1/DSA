/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    int i = 0;
    void fun(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        fun(root->left);
        res.push_back(root->val);
        fun(root->right);
    }

    void fix(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        fix(root->left);
        root->val = res[i++];
        fix(root->right);
    }

    void recoverTree(TreeNode* root) {
        fun(root);
        sort(res.begin(), res.end());
        fix(root);
    }
};