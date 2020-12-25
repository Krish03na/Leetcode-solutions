class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        int m=INT_MAX;
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            if(prices[i]<m){
                m=prices[i];
            }else if(prices[i]-m>maxProfit){
                maxProfit=prices[i]-m;
            }
        }
        return maxProfit;
    }
};