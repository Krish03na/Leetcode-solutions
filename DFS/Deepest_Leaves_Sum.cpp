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
//     int ans=0;
//     void sum_of_deepest_leaves(TreeNode* root, int curdepth, int maxd){
//         if(!root) return;
//         if(curdepth==maxd) ans+=root->val;
//         sum_of_deepest_leaves(root->left, curdepth+1,maxd);
//         sum_of_deepest_leaves(root->right, curdepth+1,maxd);
//     }
    
//     int find_depth(TreeNode*root){
//         if(!root) return 0;
//         int l=find_depth(root->left);
//         int r=find_depth(root->right);
//         return max(l,r)+1;
//     }
    int deepestLeavesSum(TreeNode* root) {
        //sol1
        // if(!root) return 0;
        // int d=find_depth(root);
        // sum_of_deepest_leaves(root,1,d);
        // return ans;
        
        //bfs
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            ans=0;
            while(sz--){
                TreeNode*temp=q.front();
                q.pop();
                ans+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
    }
};