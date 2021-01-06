class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<vector<int>>& graph, vector<int>v, int n, int c){
        if(c==n-1){
            // v.push_back(c);
            ans.push_back(v);
            return;
        }
        for(int i=0;i<graph[c].size();i++){
            v.push_back(graph[c][i]);
            find(graph,v,n,graph[c][i]);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>v;
        v.push_back(0);
        find(graph,v,n,0);
        return ans;
    }
};