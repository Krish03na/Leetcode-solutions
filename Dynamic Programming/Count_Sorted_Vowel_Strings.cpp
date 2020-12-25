class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>a(5,1);
        for(int i=1;i<n;i++){
            for(int j=3;j>=0;j--){
                a[j]+=a[j+1];
            }
        }
        return accumulate(a.begin(), a.end(),0);
        
    }
};