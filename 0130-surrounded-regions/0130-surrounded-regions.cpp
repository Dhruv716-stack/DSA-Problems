class Solution {
public:
void dfs(vector<vector<char>>& board,int delr[],int delc[],vector<vector<int>>&vis,int r,int c)
{
    int m=board.size();
    int n=board[0].size();
    vis[r][c]=1;
    for(int i=0;i<4;i++)
    {
        int nr=r+delr[i];
        int nc=c+delc[i];
        if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && board[nr][nc]=='O') dfs(board,delr,delc,vis,nr,nc);
    }
    return;
}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0 ||i==m-1 || j==n-1)
                {
                    if(board[i][j]=='O')
                    {
                        vis[i][j]=1;
                        dfs(board,delr,delc,vis,i,j);
                    }
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