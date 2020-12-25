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
    
    void find(TreeNode* root, vector<int>&lo){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            lo.push_back(root->val);
            return;
        }
        find(root->left,lo);
        find(root->right,lo);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>lo1,lo2;
        find(root1,lo1);
        find(root2,lo2);
        if(lo1==lo2) return true;
        return false;
    }
};