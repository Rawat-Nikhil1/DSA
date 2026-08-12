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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if (root == NULL) {
            return {};
        }
        q.push(root);
        int i = 1;

        while (!q.empty()) {
            int lvl = q.size();
            vector<int> temp;

            while (lvl--) {
                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if (t->left != NULL) {
                    q.push(t->left);
                }

                if (t->right != NULL) {
                    q.push(t->right);
                }
            }
            if (i % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            i++;
        }
        return res;
    }
};