class Solution {
public:
    void bfs(int sr, int sc, vector<vector<int>>& vis, vector<vector<char>>&grid){
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;

        vector<int> del_r={-1,0,1,0};
        vector<int> del_c={0,1,0,-1};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+del_r[i];
                int nc=c+del_c[i];
                if(nr>=0 && nr< m && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    bfs(i,j,vis,grid);
                    cnt++;
                    vis[i][j]=1;
                }
            }
        }

        return cnt;
    }
};