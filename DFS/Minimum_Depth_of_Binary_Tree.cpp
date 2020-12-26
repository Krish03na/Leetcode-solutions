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
//     int ans=INT_MAX;
//     void find(TreeNode*root,int depth){
//         if(root==NULL) return;
//         find(root->left, depth+1);
//         find(root->right, depth+1);
//         if(!root->left && !root->right) ans=min(ans,depth);
        
//     }
    int minDepth(TreeNode* root, int depth=0) {
        //sol1
        // if(!root) return 0;
        // find(root,1);
        // return ans;
        
        //sol2
        return !root ? depth : (!root->left && !root->right) ? depth + 1 : min(root->left ? minDepth(root->left, depth + 1) : INT_MAX, root->right ? minDepth(root->right, depth + 1) : INT_MAX);
        
    }
};