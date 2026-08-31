/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>res;
    void fun(TreeNode* root){

        if(root == NULL){
            return;
        }
        
        fun(root->left);
        res.push_back(root->val);
        fun(root->right);
    }
    bool isValidBST(TreeNode* root) {
        fun(root);

        int n = res.size();

        for(int i=1 ; i<n ;i++){
            if(res[i-1]>=res[i]){
                return false;
            }
        }
        return true;
    }
};