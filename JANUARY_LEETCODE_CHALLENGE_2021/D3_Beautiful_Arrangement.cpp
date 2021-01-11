class Solution {
public:
    int ans=0;
    void permute(vector<int> &nums, int ci, int n){
        if(ci==n+1){
            // int i;
            // for(i=1;i<=n;i++){
            //     if(nums[i]%i!=0 && i%nums[i]!=0){
            //         break;
            //     }
            // }
            // if(i==n+1){
                ans++;
            // }
            // return;
        }
        for(int i=ci;i<=n;i++){
            swap(nums[ci],nums[i]);
            if(nums[ci]%ci==0 || ci%nums[ci]==0)
            permute(nums,ci+1,n);
            swap(nums[ci],nums[i]);
        }
        
    }
    int countArrangement(int n) {
        vector<int> nums(n+1,0);
        for(int i=1;i<=n;i++){
            nums[i]=i;
        }
        permute(nums,1,n);
        return ans;
    }
};