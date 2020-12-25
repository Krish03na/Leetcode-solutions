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
    void store(vector<int>&v, TreeNode* root){
        if(root==NULL) return;
        
        store(v, root->left);
        v.push_back(root->val);
        store(v, root->right);
    }
    TreeNode*cur;
    void inorder(TreeNode*node){
        if(node==NULL) return;
        inorder(node->left);
        node->left=NULL;
        cur->right=node;
        cur=node;
        inorder(node->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        //approach1
        // if(root==NULL) return NULL;
        // vector<int>v;
        // store(v,root);
        // TreeNode*ans=new TreeNode;
        // ans->val=v[0];
        // TreeNode*tr=ans;
        // if(v.size()==1) return ans;
        // for(int i=1;i<v.size();i++){
        //     tr->right=new TreeNode(v[i]);
        //     tr=tr->right;
        // }
        // return ans;
        
        //approach2
        TreeNode*ans=new TreeNode(0);
        cur=ans;
        inorder(root);
        return ans->right;
        
    }
};