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
    int sumEvenGrandparent(TreeNode* root) {
        //sol1
//         if(!root) return 0;
//         int s=0;
//         if(root->val%2==0){
//             if(root->left){
//                if(root->left->left) s+=root->left->left->val;
//                 if(root->left->right) s+=root->left->right->val;
//             }
//             if(root->right){
//                if(root->right->left) s+=root->right->left->val;
//                 if(root->right->right) s+=root->right->right->val;
//             }
            
//         }
        
//         return s+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
        
        //bfs
        int ans=0;
        if(root){
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    if(temp->val%2==0){
                        if(temp->left->left){
                            ans+=temp->left->left->val;
                        }
                        if(temp->left->right){
                            ans+=temp->left->right->val;
                        }
                    }
                    
                }
                if(temp->right){
                    q.push(temp->right);
                    if(temp->val%2==0){
                        if(temp->right->left){
                            ans+=temp->right->left->val;
                        }
                        if(temp->right->right){
                            ans+=temp->right->right->val;
                        }
                    }
                }
            }
        }
        return ans;
        
        
        
        
        
        
        
        
        
    }
};