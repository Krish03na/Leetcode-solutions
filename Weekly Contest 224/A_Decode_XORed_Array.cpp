class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        vector<int>a(n+1);
        a[0]=first;
        for(int i=1;i<=n;i++){
            a[i]=encoded[i-1]^a[i-1];
        }
        return a;
    }
};