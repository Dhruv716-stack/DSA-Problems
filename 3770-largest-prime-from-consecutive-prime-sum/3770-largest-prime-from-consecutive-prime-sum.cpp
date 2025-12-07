class Solution {
public:
    vector<bool> prime(int n)
    {
        vector<bool> is_prime(n+1,1);
        if(n>=0) is_prime[0]=0;
        if(n>=1) is_prime[1]=0;
        for(int i=2;i<=n;i++)
        {
            if(is_prime[i]==1)
            {
                for(int j=2*i;j<=n;j+=i)
                {
                    is_prime[j]=0;
                }
            }
        }
        return is_prime;
    }
    vector<long long> p_sum(vector<bool>&is_prime)
    {
        int n1=is_prime.size();
        vector<long long>p(n1+1,0);
        for(int i=2;i<=n1;i++)
        {
            p[i]=p[i-1];
            if(is_prime[i-1]==1)
            {
                p[i]+=(i-1);
            }
        }
        return p;
    }
    int largestPrime(int n) {
        vector<bool> is_prime=prime(n);
        vector<long long> prime_sum=p_sum(is_prime);
        int n1=prime_sum.size();
        long long ans=0;
        for(int i=0;i<n1;i++)
        {
            if( prime_sum[i]<=n && is_prime[prime_sum[i]]==1)
            {
                ans=max(ans,prime_sum[i]);
            }
        }
        return ans;
    }
};