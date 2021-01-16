class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        //m1
        // sort(nums.begin(), nums.end());
        // return nums[n-k];
        
        //m2
        priority_queue<int>pq;
        for(int i=0;i<n;i++) pq.push(nums[i]);
        --k;
        while(k--) pq.pop();
        return pq.top();
    }
};