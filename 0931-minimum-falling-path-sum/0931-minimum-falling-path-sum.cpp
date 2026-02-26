class Solution {
public:
    long long solve(int i, int j, vector<vector<int>>&mat,vector<vector<long long>>&dp)
    {
        int n=mat.size();
        if(i==n-1)
        {
            if(j<n && j>=0) return 1LL*mat[i][j];
            return INT_MAX;
        }
        if(j>=n || j<0) return INT_MAX;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        long long p1=INT_MAX,p2=INT_MAX,p3=INT_MAX;
        p1=1LL*mat[i][j]+solve(i+1,j+1,mat,dp);
        p2=1LL*mat[i][j]+solve(i+1,j,mat,dp);
        p3=1LL*mat[i][j]+solve(i+1,j-1,mat,dp);
        return dp[i][j]=min({p1,p2,p3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,1e7));
        long long mini=INT_MAX;

        for(int i=0;i<n;i++) dp[n-1][i]=matrix[n-1][i];

        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                long long p1=1e7,p2=1e7,p3=1e7;
                if(j+1<n)p1=1LL*matrix[i][j]+dp[i+1][j+1];
                p2=1LL*matrix[i][j]+dp[i+1][j];
               if(j-1>=0) p3=1LL*matrix[i][j]+dp[i+1][j-1];
                dp[i][j]=min({p1,p2,p3});
            }
        }

        for(int i=0;i<n;i++)
        {
            mini= min(mini,dp[0][i]);
        }
        return mini;
    }
};