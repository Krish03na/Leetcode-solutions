class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int n=a.size();
        int ans=0;
        if(n==1){
            
            if(a[0]==1) ans= k+1;
            else{
                if(k<a[0]){
                    ans= k;
                }else{
                    ans= k+1;
                }
            }
            
        }else if(a[n-1]-n<k){
            ans= k+n;
        }else
        for(int i=0;i<n;i++){
            if(a[i]-i-1>=k){
                ans= a[i]-((a[i]-i-1)-k+1);
                break;
            }
        }
        return ans;
    
    }
};