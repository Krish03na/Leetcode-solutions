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
    bool ans=true;
    int find(TreeNode*root){
        if(!root) return 0;
        int l=find(root->left);
        int r=find(root->right);
        if(abs(l-r)>1) ans=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        find(root);
        return ans;
    }
    
};