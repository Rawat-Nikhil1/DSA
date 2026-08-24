class Solution {
public:
    vector<int> res;

    void fun(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (level == res.size()) {
            res.push_back(root->val);
        }
        fun(root->right, level + 1);
        fun(root->left, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        fun(root, 0);
        return res;
    }
};