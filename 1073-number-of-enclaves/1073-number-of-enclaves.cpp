class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int delr[],int delc[],int r, int c)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]==1) dfs(grid,vis,delr,delc,nr,nc);
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1 && vis[0][i]==0)
            {
                vis[0][i]=1;
                dfs(grid,vis,delr,delc,0,i);
            }
            if(grid[m-1][i]==1 && vis[m-1][i]==0)
            {
                vis[m-1][i]=1;
                dfs(grid,vis,delr,delc,m-1,i);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1 && vis[i][0]==0)
            {
                vis[i][0]=1;
                dfs(grid,vis,delr,delc,i,0);
            }
            if(grid[i][n-1]==1 && vis[i][n-1]==0)
            {
                vis[i][n-1]=1;
                dfs(grid,vis,delr,delc,i,n-1);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};