class Solution {
public:
    int solve(vector<vector<int>>&tri,int i,int j,vector<vector<int>>&dp)
    {
        int m=tri.size();
        if(i==m-1) return tri[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int d=INT_MAX,dg=INT_MAX;
        d=tri[i][j]+solve(tri,i+1,j,dp);
        dg=tri[i][j]+solve(tri,i+1,j+1,dp);
        return dp[i][j]=min(d,dg);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++)
        {
            dp[m-1][j]=triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int d=triangle[i][j]+dp[i+1][j];
                int dg=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d,dg);
            }
        }
        return dp[0][0];

    }
};