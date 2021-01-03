//sol1 brute force with optimisation
// class Solution {
// public:
//     int ans=0;
//     void permute(vector<int> &nums, int ci, int n){    
//         if(ci==n+1){
//                 ans++;
//         }
//         for(int i=ci;i<=n;i++){
//             swap(nums[ci],nums[i]);
//             if(nums[ci]%ci==0 || ci%nums[ci]==0)
//             permute(nums,ci+1,n);
//             swap(nums[ci],nums[i]);
//         }
        
//     }
//     int countArrangement(int n) {
        
//         vector<int> nums(n+1,0);
//         for(int i=1;i<=n;i++){
//             nums[i]=i;
//         }
//         permute(nums,1,n);
//         return ans;
//     }
        
// };

//sol2 using backtracking
class Solution {
public:
    int ans=0;
    void calculate(int n, int pos, bool*vis){
        if(pos>n) ans++;
        for(int i=1;i<=n;i++){
            if(!vis[i] && (pos%i==0 || i%pos==0)){
                vis[i]=true;
                calculate(n,pos+1,vis);
                vis[i]=false;
            }
        }
    }
    int countArrangement(int n) {
        bool*vis=new bool[n+1];
        for(int i=0;i<n+1;i++) vis[i]=false;
        calculate(n,1,vis);
        return ans;
    }
};