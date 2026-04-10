class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i , int j ,int k,vector<vector<int>>&grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n) return -1e8;
        if(k<0) return -1e8;
        if(i==m-1 && j==n-1)
        {
            if(k>0) return grid[i][j];
            else
            {
                if(grid[i][j]>0) return -1e8;
                else return 0;
            }
        }
        if(dp[i][j][k]!=-1e8) return dp[i][j][k];
        int p1=-1e8,p2=-1e8;
        int t1=-1e8,t2=-1e8,t3=-1e8,t4=-1e8;
        if(grid[i][j]!=0)
        {
            t1=grid[i][j]+solve(i+1,j,k-1,grid);
            t2=grid[i][j]+solve(i,j+1,k-1,grid);
        }
        else if(grid[i][j]==0)
        {
            t3=solve(i+1,j,k,grid);
            t4=solve(i,j+1,k,grid);
        }
        p1=max(t1,t3);
        p2=max(t2,t4);
        return dp[i][j][k]=max(p1,p2);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(k+1,-1e8)));
        int ans=solve(0,0,k,grid);
        if(ans<0) return -1;
        return ans;

    }
};