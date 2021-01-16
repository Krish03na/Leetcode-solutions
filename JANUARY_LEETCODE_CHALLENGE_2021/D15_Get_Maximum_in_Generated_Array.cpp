class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        if(n<2) return 1;
        int a[n+1];
        a[0]=0;
        a[1]=1;
        int mx=1;
        for(int i=2;i<n+1;i++){
            if(i%2==0){
                a[i]=a[i/2];
            }else{
                a[i]=a[(i-1)/2]+a[(i+1)/2];
            }
            mx=max(mx,a[i]);
        }
        return mx;
    }
};