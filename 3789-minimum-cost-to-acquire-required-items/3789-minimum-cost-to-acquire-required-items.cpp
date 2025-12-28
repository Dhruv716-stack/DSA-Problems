class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long ans=0;
        if(cb<c1+c2)
        {
             ans+= cb*1LL*min(n1,n2);
            if(n1>n2)
            {
                int extra=n1-n2;
                long long tc2=0;
                if(c1>cb) ans+=cb*1LL*extra;
                else ans+=c1*1LL*extra;
            }
            else if(n2>n1)
            {
                int extra=n2-n1;
                if(c2>cb) ans+=cb*1LL*extra;
                else ans+=c2*1LL*extra;
            }
        }
        else
        {
            ans+=c1*1LL*n1;
            ans+=c2*1LL*n2;
        }
        return ans;
    }
};
