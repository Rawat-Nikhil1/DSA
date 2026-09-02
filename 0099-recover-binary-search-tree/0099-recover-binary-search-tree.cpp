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
        int n = res.size();
        int mistake = 0;
        int m1first, m1second, m2first, m2second;
        for (int i = 0; i < n - 1; i++) {
            if (res[i] > res[i + 1]) {
                if (mistake == 0) {
                    m1first = i;
                    m1second = i + 1;
                    mistake++;
                } else {
                    m2first = i;
                    m2second = i + 1;
                    mistake++;
                }
            }
        }
        if (mistake == 1) {
            swap(res[m1first], res[m1second]);
        } else {
            swap(res[m1first], res[m2second]);
        }
        fix(root);
    }
};