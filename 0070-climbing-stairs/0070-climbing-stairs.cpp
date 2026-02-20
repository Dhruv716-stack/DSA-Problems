class Solution {
public:
    int solve(int i,vector<int>&dp,int n)
    {
        if(i==0) return 1;
        if(i==1) return 1;
        if(dp[i]!=-1) return dp[i];
        int l=0,r=0;
        l=solve(i-1,dp,n);
        r=solve(i-2,dp,n);
        return dp[i]=l+r;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp,n);
    }
};