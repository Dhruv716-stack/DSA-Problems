class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt0=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }

                else if(grid[i][j]==0){
                    cnt0++;
                }
            }
        }

        if(cnt0==m*n) return 0;

        

        vector<int> del_x={0,1,0,-1};
        vector<int> del_y={1,0,-1,0};

        int ans=0;

        while(!q.empty()){
            int s=q.size();
            ans++;
            for(int i=0;i<s;i++){
                auto [x,y]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+del_x[k];
                    int ny=y+del_y[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==0 && grid[nx][ny]==1){
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                        grid[nx][ny]=2;
                    }
                }

            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                    }
                }
            }

            return ans-1;
    }
};