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
    void fun(TreeNode* node, vector<int>& res) {
        if (node == NULL) {
            return;
        }
        fun(node->left, res);
        res.push_back(node->val);
        fun(node->right, res);

        return;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        fun(root, res);
        int n = res.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (res[i] + res[j] == k) {
                return true;
            } else if (res[i] + res[j] > k) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};