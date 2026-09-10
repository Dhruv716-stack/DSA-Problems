class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        vis[r][c]=1;
        int ans=1;
        vector<int> del_r={-1,0,1,0};
        vector<int> del_c={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr=r+del_r[i];
            int nc=c+del_c[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]==1){
                ans+=dfs(nr,nc,vis,grid);
            }
        }

        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    ans=max(ans,dfs(i,j,vis,grid));
                    vis[i][j]=1;
                }
            }
        }

        return ans;
    }
};