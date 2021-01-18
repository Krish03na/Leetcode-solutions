class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int i=0,j=n-1,ans=0;
        while(i<j){
            int s=nums[i]+nums[j];
            if(s==k){
                ans++;
                i++;
                j--;
            }else if(s<k){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};