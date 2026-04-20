class Solution {
public:
    
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<tuple<int,int,int>> q;
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        for(auto &it:sources)
        {
            int r=it[0],c=it[1],color=it[2];
            grid[r][c]=color;
            dist[r][c]=0;
            q.push({color,r,c});
        }
        vector<int> delr={-1,0,1,0};
        vector<int> delc={0,-1,0,1};
        while(!q.empty())
        {
            auto [color,r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    if(dist[nr][nc]>dist[r][c]+1)
                    {
                        dist[nr][nc]=dist[r][c]+1;
                        grid[nr][nc]=color;
                        q.push({color,nr,nc});
                    }
                    else if(dist[nr][nc]==dist[r][c]+1 && grid[nr][nc]<color)
                    {
                        grid[nr][nc]=color;
                        q.push({color,nr,nc});
                    }
                }
            }
        }
        return grid;
    }
};