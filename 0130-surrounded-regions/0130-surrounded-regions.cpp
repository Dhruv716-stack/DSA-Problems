class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                {
                    if(i==0||i==m-1||j==0 || j==n-1)
                    {
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
                
            }
        }
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            for(int i=0;i<4;i++)
            {
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O' && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[i][j]=='O' && vis[i][j]==0) board[i][j]='X';
                }
            }
        
        return;
    }
};