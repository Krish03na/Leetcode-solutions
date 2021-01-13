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
//     void getPath(TreeNode*root, vector<int>& f){
//         if(!root) return;
//         f[root->val]++;
//         if(!root->left && !root->right){
//             int od=0;
//             for(int i=0;i<10;i++){
//                 if(f[i]&1) od++;
//             }
//             if(od<=1) ans++;
//             f[root->val]--;
//             return;
//         }
        
//         getPath(root->left,f);
//         getPath(root->right,f);
//         f[root->val]--;
//     }
    int pseudoPalindromicPaths (TreeNode* root, int c=0) {
        //solution1
        // vector<int>f(10,0);
        // getPath(root,f);
        // return ans;
        
        
        //solution2
        if(!root) return 0;
        c^= 1 << root->val;
        if(!root->left && !root->right){
            if(c&(c-1)){
                return 0;
            }else{
                return 1;
            }
        }
        int l= pseudoPalindromicPaths(root->left,c);
        int r= pseudoPalindromicPaths(root->right,c);
        return l+r;
        
    }
};