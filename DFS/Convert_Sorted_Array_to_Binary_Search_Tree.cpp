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
    TreeNode*find(vector<int>& nums, int s, int e){
        if(s>e) return NULL;
        int mid=s+(e-s)/2;
        if(mid<s || mid>e) return NULL;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=find(nums,s,mid-1);
        root->right=find(nums,mid+1,e);
        return root;
        
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return find(nums,0,nums.size()-1);
    }
};