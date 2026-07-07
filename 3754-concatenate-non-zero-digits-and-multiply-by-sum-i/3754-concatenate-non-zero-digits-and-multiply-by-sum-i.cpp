class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        ll rev1=n%10,sum=n%10;
        n=n/10;
        while(n>0){
            ll r=n%10;
            if(r!=0){
                sum+=r;
                (rev1=rev1*10+r);
            }
            n=n/10;
        }

        ll rev2=rev1%10;
        rev1=rev1/10;
        while(rev1>0){
            ll r=rev1%10;
            if(r!=0){
                (rev2=rev2*10+r);
            }
            rev1=rev1/10;
        }

        return (rev2*sum);


    }
};