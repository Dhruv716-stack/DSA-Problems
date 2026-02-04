class Solution {
public:
    typedef long long ll;
    ll solve(int i, int t,vector<int>&nums,vector<vector<ll>>&dp)
    {
        int n=nums.size();
        if(i>=n)
        {
            if(t==3) return 0;
            else
            {
                return LLONG_MIN/2;
            }
        }
        if(dp[i][t]!=-1) return dp[i][t];

        ll skip=LLONG_MIN/2;
        ll take=LLONG_MIN/2;
        if(t==0)
        {
            skip=solve(i+1,0,nums,dp);
        }
        if(t==3)
        {
            take=nums[i];
        }

        if(i+1<n)
        {
            int curr=nums[i];
            int next=nums[i+1];
            if(t==0)
            {
                if(next>curr)
                {
                    take=max(take,curr+solve(i+1,1,nums,dp));
                }
            }
            else if(t==1)
            {
                if(next>curr)
                {
                    take=max(take,curr+solve(i+1,1,nums,dp));
                }
                else if(next<curr)
                {
                    take=max(take,curr+solve(i+1,2,nums,dp));
                }
            }
            else if(t==2)
            {
                if(next<curr)
                {
                    take=max(take,curr+solve(i+1,2,nums,dp));
                }
                else if(next>curr)
                {
                    take=max(take,curr+solve(i+1,3,nums,dp));
                }
            }
            else if(t==3 && next>curr)
            {
                take=max(take,curr+solve(i+1,3,nums,dp));
            }
        }
        return dp[i][t]=max(skip,take);
    }
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>> dp(n,vector<ll>(4,-1));
        return solve(0,0,nums,dp);
    }
};