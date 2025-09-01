class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        int ans=-1;
        if(n==1 && grid[0][0]==0) return 1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<pair<int,int>,int>> q;
        int del_r[8]={-1,-1,0,1,1,1,0,-1};
        int del_c[8]={0,1,1,1,0,-1,-1,-1};
        q.push({{0,0},1});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int r=p.first.first;
            int c=p.first.second;
            int dis=p.second;
            if(r==n-1 && c==n-1)
            {
                ans=dis;
                break;
            }
            for(int i=0;i<8;i++)
            {
                int nr=r+del_r[i];
                int nc=c+del_c[i];
                int cnt=0;
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    q.push({{nr,nc},dis+1});
                }
                else cnt++;
                if(cnt==8) return -1;
            }
            
        }
        return ans;
    }
};