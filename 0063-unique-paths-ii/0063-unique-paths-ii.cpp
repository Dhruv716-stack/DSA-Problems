class Solution {
public:
    int solve(int m,int n,int r,int c,vector<vector<int>>&dp,vector<vector<int>>&grid)
    {
        if(grid[0][0]==1) return 0;
        if(r==m-1 &&c==n-1 && grid[r][c]!=1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int l=0,ri=0;
        if(r>=0 && r<m && c>=0 && c<n)
        {

            if(r+1<m && grid[r+1][c]!=1) l=solve(m,n,r+1,c,dp,grid);
            if(c+1<n && grid[r][c+1]!=1) ri=solve(m,n,r,c+1,dp,grid);
        }

        return dp[r][c]=l+ri;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=solve(m,n,0,0,dp,obstacleGrid);
        return ans;
    }
};