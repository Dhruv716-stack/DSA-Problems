class Solution {
public:
    int maxProduct(int n) {
        int m=n;
        long long mx1=0,mx2=0;
        while(n>0){
            long long r=1LL*(n%10);
            mx1=max(mx1,r);
            n=n/10;
        }
        int cnt=0;
        while(m>0){
            long long r=1LL*(m%10);
            if(r==mx1 && cnt==0){
                cnt++;
                m=m/10;
                continue;
            }
            mx2=max(r,mx2);
            m=m/10;
        }
        return (int)(mx1*mx2);
    }
};