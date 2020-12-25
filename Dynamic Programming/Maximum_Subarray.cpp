class Solution {
public:
    int merge(vector<int>& nums, int s, int mid, int e){
        int fe=0,em=INT_MIN;
        int fs=0,sm=INT_MIN;
        for(int i=mid;i>=s;i--){
            fe+=nums[i];
            em=max(em,fe);
        }
        for(int i=mid+1;i<=e;i++){
            fs+=nums[i];
            sm=max(sm,fs);
        }
        return em+sm;
    }
    
    int find(vector<int>& nums, int s, int e){
        int n=e-s+1;
        if(s>e) return INT_MIN;
        if(n==1) return nums[s];
        int mid=(s+e)/2;
        int left=find(nums,s,mid);
        int right=find(nums,mid+1,e);
        int ms=merge(nums,s,mid,e);
        return max(max(left,right),ms);
    }
    
    int maxSubArray(vector<int>& nums) {
        //1. using kadane algo
        int n=nums.size();
        // int cs=0, ms=INT_MIN;
        // for(int i=0;i<n;i++){
        //     cs+=nums[i];
        //     ms=max(ms,cs);
        //     if(cs<0) cs=0;
        // }
        // return ms;
        
        //2. using divide and conquer
        return find(nums, 0, n-1);
    }
};