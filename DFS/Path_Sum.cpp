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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            // if(sum==0) return true;
            return false;
        }
        if(root->val==sum && !root->left && !root->right) return true;
        bool l=false;
        bool r=false;
        l=hasPathSum(root->left, sum-root->val);
        r=hasPathSum(root->right, sum-root->val);
        return l|r;
    }
};