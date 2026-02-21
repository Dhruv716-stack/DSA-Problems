class Solution {
public:
    
    vector<bool> sieve(int N)
    {
        vector<bool> isPrime(N+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i<N;i++)
       {
        if(isPrime[i]==true)
       { for(int j=2*i;j<N;j+=i)
        {
            isPrime[j]=false;
        }}
        }
        return isPrime;
    }
    int countPrimeSetBits(int left, int right) {
        const int N=1e6+7;
        vector<bool> is_prime=sieve(N);
        int cnt=0;
        for(int i=left;i<=right;i++)
        {
            int n=__builtin_popcount(i);
            if(is_prime[n]==true) cnt++;
        }
        return cnt;
    }
};