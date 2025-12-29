#define ll long long
class Solution {
public:
    /*ll solve(int i, vector<int>&arr,vector<ll>&dp,int k)
    {
        int n=arr.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        ll max_ans=LLONG_MIN;
        int len=0;
        int maxi=INT_MIN;
        for(int j=i;j<min(i+k,n);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            ll sum=len*maxi*1LL +solve(j+1,arr,dp,k);
            max_ans=max(max_ans,sum);
        }
        return dp[i]=max_ans;
    }*/
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<ll> dp(n+1,0);
        ll max_ans=LLONG_MIN;
        for(int i=n-1;i>=0;i--)
        {
            int len=0;
            int maxi=INT_MIN;
            for(int j=i;j<min(i+k,n);j++)
            {
                len++;
                maxi=max(maxi,arr[j]);
                ll sum=len*maxi*1LL+dp[j+1];
                max_ans=max(max_ans,sum);
            }
            dp[i]=max_ans;
        }
        return dp[0];
    }
};