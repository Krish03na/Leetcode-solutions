/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // int ans=0;
    // void dfs(Node*root, int level){
    //     if(!root) return;
    //     ans=max(ans,level);
    //     for(auto c: root->children){
    //         dfs(c,level+1);
    //     }
    // }
    int maxDepth(Node* root) {
        //sol1
        // dfs(root,1);
        // return ans;
        
        //sol2
        if(root==NULL) return 0;
        queue<Node*>q;
        q.push(root);
        int depth=0;
        while(!q.empty()){
            int qsize=q.size();
            depth++;
            for(int i=0;i<qsize;i++){
                Node*temp=q.front();
                q.pop();
                for(auto c:temp->children){
                    q.push(c);
                }
            }
        }
        return depth;
        
    }
};