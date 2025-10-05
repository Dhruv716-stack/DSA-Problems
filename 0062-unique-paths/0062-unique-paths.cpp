class Solution {
public:
    int solve(int m,int n,int r,int c,vector<vector<int>>&dp)
    {
        if(r==m-1 &&c==n-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int l=0,ri=0;
        if(r>=0 && r<m && c>=0 && c<n)
        {
            l=solve(m,n,r+1,c,dp);
            ri=solve(m,n,r,c+1,dp);
        }

        return dp[r][c]=l+ri;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans=solve(m,n,0,0,dp);
        return ans;
    }
};