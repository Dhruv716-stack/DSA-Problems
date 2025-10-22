class Solution {
public:
    int solve(vector<vector<int>>&grid,int r,int c,vector<vector<int>>&dp)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(r==0 && c==0)
        {
            return grid[0][0];  
        }
        if(r<0 || c<0) return INT_MAX;
        if(dp[r][c]!=INT_MAX) return dp[r][c];
        int up=INT_MAX,left=INT_MAX;
        if(r>0) up=grid[r][c]+solve(grid,r-1,c,dp);
        if(c>0) left=grid[r][c]+solve(grid,r,c-1,dp);
        return dp[r][c]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        int ans=solve(grid,m-1,n-1,dp);
        return ans;
    }
};