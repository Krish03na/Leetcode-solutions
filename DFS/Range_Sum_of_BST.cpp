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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        if(root==NULL) return 0;
        int v=root->val;
        if(v>=low && v<=high) ans+=v;
        int l = rangeSumBST(root->left, low, high);
        int r = rangeSumBST(root->right, low, high);
        return ans+l+r;
    }
};