class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int temp=nums[0]+nums[1]+nums[2];
        int i=0;
        while(i<n-2){
            int l=i+1,r=n-1;
            while(l<r){
                int s=nums[i]+nums[l]+nums[r];
                if(abs(s-target)<abs(target-temp)){
                    temp=s;
                }
                if(s>target){
                    r--;
                }else if(s<target){
                    l++;
                }else return target;
            }
            i++;
        }
        return temp;
    }
};