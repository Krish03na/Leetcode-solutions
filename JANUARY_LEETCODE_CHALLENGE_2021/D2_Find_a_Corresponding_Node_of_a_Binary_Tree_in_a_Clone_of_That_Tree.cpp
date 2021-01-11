/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool findpath(TreeNode* original, TreeNode* target, vector<int>&v){
        if(original==target){
            return true;
        }
        if(original==NULL) return false;
        bool ans=false;
        if(findpath(original->right, target,v)){
            v.push_back(1);
            ans=true;
        }else if(findpath(original->left,target,v)){
            v.push_back(0);
            ans=true;
        }
        return ans;
    }
    
    TreeNode*gotopath(TreeNode*cloned, vector<int>v){
        TreeNode*ans=cloned;
        for(int i=0;i<v.size();i++){
            if(v[i]) ans=ans->right;
            else ans=ans->left;
        }
        return ans;
    }
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<int>v;
        findpath(original, target, v);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        reverse(v.begin(),v.end());
        return gotopath(cloned,v);
        // return NULL;
    }
};