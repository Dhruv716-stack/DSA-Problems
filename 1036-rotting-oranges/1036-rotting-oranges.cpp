class Solution {
public:
    int bfs(vector<vector<int>>&grid,queue<pair<int,int>> &q)
    {
        int cnt1=0;
        int m=grid.size();
        int n=grid[0].size();
        while(!q.empty())
        {
            int size=q.size();
            int cnt=0;
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                int x=node.first;
                int y=node.second;
                if(x+1<m && grid[x+1][y]==1)
                {
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                    cnt++;
                }
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                    cnt++;
                }
                if(y+1<n && grid[x][y+1]==1)
                {
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                    cnt++;
                }
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                    cnt++;
                }
            }
            if(cnt>0) cnt1++;
        }
        return cnt1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2) q.push({i,j});
            }
        }

        int ans=bfs(grid,q);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;

    }
};