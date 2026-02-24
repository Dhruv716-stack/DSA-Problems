class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&tri,vector<vector<long long>>&dp)
    {
        int n=tri.size();
        if(i==n-1)
        {
            if(j<=i) return tri[i][j];
            return INT_MAX;
        }
        if(j>i) return INT_MAX;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        long long p1=INT_MAX,p2=INT_MAX;
        p1=1LL*tri[i][j]+solve(i+1,j,tri,dp);
        p2=1LL*tri[i][j]+solve(i+1,j+1,tri,dp);
        return dp[i][j]=min(p1,p2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<long long>> dp(n,vector<long long>(n,INT_MAX));
        return solve(0,0,triangle,dp);

    }
};