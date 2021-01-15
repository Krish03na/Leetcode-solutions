class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=0;
        for(int i:nums){
            total+=i;
        }
        int left=0,right=0,cur=0, mx=-1;
        if(x>total) return -1;
        while(right<n){
            cur+=nums[right];
            while(cur>total-x){
                cur-=nums[left];
                ++left;
            }
            if(cur==total-x){
                mx=max(mx,right-left+1);
            }
            right++;
        }
        if(mx!=-1) return n-mx;
        else return mx;
        
    }
};