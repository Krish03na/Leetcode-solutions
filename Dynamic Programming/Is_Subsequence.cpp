class Solution {
public:
    int find(string s, string t, int id){
        int n=s.length();
        if(id==n) return true;
        int pos = t.find(s[id]);
        if(pos==-1) return false;
        else{
            if(find(s,t.substr(pos+1),id+1)) 
                return true;
            else 
                return false;
        }
        
     }
    bool isSubsequence(string s, string t) {
        int n=s.length(), m=t.length();
        if(n==0) return true;
        if(m==0) return false;
        return find(s,t,0);
    }
};