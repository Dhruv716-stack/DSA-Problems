class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int r=p.first.first;
            int c=p.first.second;
            int dist=p.second;
            for(int i=0;i<4;i++)
            {
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr<m && nr>=0 && nc<n && nc>=0 && mat[nr][nc]==1 && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    q.push({{nr,nc},dist+1});
                    ans[nr][nc]=dist+1;
                }
            }
        }
        return ans;

    }
};