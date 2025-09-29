class Solution {
public:
    int cnt=0;
    int solve(int n,vector<int>&dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(n==1) return 1;
        int l=0;
        int r=0;
        if(dp[n]!=-1) return dp[n];
        l=solve(n-1,dp);
        r=solve(n-2,dp);
        return dp[n]=l+r;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans=solve(n,dp);
        return ans;
    }
};