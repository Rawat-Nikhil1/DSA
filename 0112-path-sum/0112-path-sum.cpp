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
    bool res = false;
    void fun(TreeNode* root, int& targetSum, int& sum) {

        if (root == NULL) {
            return;
        }
        sum = sum + root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                res = true;
            }
        }
        else {
            fun(root->left, targetSum, sum);
            fun(root->right, targetSum, sum);
        }
        sum = sum - root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        fun(root, targetSum, sum);

        return res;
    }
};