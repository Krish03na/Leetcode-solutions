class Solution {
public:
    
    
    bool find(vector<int>& arr,vector<int>& piece,vector<int>& vis){
        int n=arr.size();
        int m=piece.size();
        for(int i=0;i<n-m+1;i++){
            int f=0;
            if(arr[i]==piece[0] && vis[i]==0){
                for(int j=0;j<m;j++){
                    if(piece[j]!=arr[i+j] || vis[i]==1){
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    for(int j=i;j<i+m;j++) vis[j]=1;
                    return true;
                }
            }
        }
        return false;
    }
    
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n=arr.size();
        int m1[101]={0};
        for(int i=0;i<n;i++){
            m1[arr[i]]++;
        }
        int m=pieces.size();
        int m2[101]={0};
        for(int i=0;i<m;i++){
            for(int j=0;j<pieces[i].size();j++){
                m2[pieces[i][j]]++;
            }
        }
        for(int i=0;i<101;i++){
            if(m1[i]!=m2[i]) return  false;
        }
        vector<int> vis(n,0);
        for(int i=0;i<m;i++){
            if(!find(arr,pieces[i],vis)) return false;
        }
        return true;
    }
};