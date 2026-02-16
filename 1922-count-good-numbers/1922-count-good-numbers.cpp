class Solution {
public:
    const int M=1e9+7;
    long long solve(long long base,long long n)
    {
        if(n==0) return 1;
        long long half=(solve(base,n/2));
        long long t=(half*half)%M;
        if(n%2==1) t=(t*base)%M;
        return t;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even =(n+1)/2;
        long long p1=solve(5,even);
        long long p2=solve(4,odd);
        return (p1*p2)%M;
    }
};