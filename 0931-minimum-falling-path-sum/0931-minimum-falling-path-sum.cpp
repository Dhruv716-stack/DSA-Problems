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
        vector<vector<long long>> dp(n,vector<long long>(n,INT_MAX));
        long long mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini= min(mini,solve(0,i,matrix,dp));
        }
        return mini;
    }
};