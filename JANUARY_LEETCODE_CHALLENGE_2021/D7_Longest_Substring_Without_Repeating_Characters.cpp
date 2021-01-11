class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n<=1) return n;
        map<char, int>mp;
        int st=0,e=0,maxlen=0;
        while(e<n){
            // cout<<e<<endl;
            if(mp[s[e]]>0){
                maxlen=max(maxlen,e-st);
                while(s[st]!=s[e]){
                    mp[s[st]]--;
                    st++;
                }
                st++;
                // mp[e]--;
            }else{
                maxlen=max(maxlen,e-st+1);
                mp[s[e]]++;
            }
            
            e++;
            
        }
        return maxlen;
    }
};