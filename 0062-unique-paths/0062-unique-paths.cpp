class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int p1=0,p2=0;
        if(i-1>=0) p1=solve(i-1,j,dp);
        if(j-1>=0) p2=solve(i,j-1,dp);
        return dp[i][j]=p1+p2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};