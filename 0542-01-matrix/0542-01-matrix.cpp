class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0)), dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        vector<int> delR={-1,0,1,0};
        vector<int> delC={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr=r+delR[i];
                int nc=c+delC[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && mat[nr][nc]==1){
                        dis[nr][nc]=1+d;
                        vis[nr][nc]=1;
                        q.push({{nr,nc},d+1});
                }
            }
        }

        return dis;
    }
};