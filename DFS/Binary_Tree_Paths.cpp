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
    vector<string>ans;
    
    void findpaths(TreeNode* root, string cur){
        if(!root) return;
        else if(!root->left and !root->right){
            ans.push_back(cur+to_string(root->val));
            return;
        }
            findpaths(root->left,cur+to_string(root->val)+"->");
            findpaths(root->right,cur+to_string(root->val)+"->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        findpaths(root,"");
        return ans;
    }
};