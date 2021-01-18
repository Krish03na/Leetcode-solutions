class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int>&group, vector<bool>&vis,int start, int top){
        group[start]=top;
        vis[start]=true;
        for(int i=0;i<adj[start].size();i++){
            int cur=adj[start][i];
            if(!vis[cur]){
                dfs(adj,group,vis,cur,top);
            }
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<allowedSwaps.size();i++){
            adj[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);
            adj[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);
        }
        vector<bool>vis(n,false);
        vector<int>group(n);
         for(int i=0;i<n;i++){
            group[i]=i;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,group,vis,i,i);
            }
        }
        unordered_map<int,vector<int> >mp;
        for(int i=0;i<n;i++){
            mp[group[i]].push_back(i);
        }
        int ans=0;
        for(auto it:mp){
            vector<int>grp=it.second;
            unordered_map<int,int>check;
            for(int i=0;i<grp.size();i++){
                check[source[grp[i]]]++;
            }
            //1->index=0,1,2,4
            //target
            for(int i=0;i<grp.size();i++){
                if(check[target[grp[i]]]>0){
                    check[target[grp[i]]]--;
                }else{
                    ans++;
                }
            }
        }
        return ans;
    }
};