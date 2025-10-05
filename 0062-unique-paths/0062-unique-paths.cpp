class Solution {
public:
    /*int solve(int m,int n,int r,int c,vector<vector<int>>&dp)
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
    }*/
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int l=0,r=0;
                if(i==m-1 && j==n-1) continue;
                if(i+1<m) l=dp[i+1][j];
                if(j+1<n) r=dp[i][j+1];
                dp[i][j]=l+r;
            }
        }
        return dp[0][0];
    }
};