class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                vis[0][j]=1;
            }

            if(board[m-1][j]=='O'){
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }

            if(board[i][n-1]=='O'){
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }

        vector<int> del_r={-1,0,1,0};
        vector<int> del_c={0,1,0,-1};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+del_r[i];
                int nc=c+del_c[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && board[nr][nc]=='O'){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }

        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

        return;
    }
};