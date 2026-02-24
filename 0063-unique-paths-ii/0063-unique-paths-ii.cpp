class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
        {
            if(grid[i][j]==1) return 0;
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int p1=0,p2=0;
        if(i-1>=0 && grid[i-1][j]==0) p1=solve(i-1,j,grid,dp);
        if(j-1>=0 && grid[i][j-1]==0) p2=solve(i,j-1,grid,dp);\
        return dp[i][j]=p1+p2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obstacleGrid,dp);
        
    }
};