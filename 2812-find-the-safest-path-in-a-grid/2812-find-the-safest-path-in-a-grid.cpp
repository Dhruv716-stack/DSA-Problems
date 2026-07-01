class Solution {
public:
    vector<int> del_r={0,1,0,-1};
    vector<int> del_c={1,0,-1,0};

    bool check_path(vector<vector<int>>&dis,int mid){
        int n=dis.size();
        if(dis[0][0]<mid) return false;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            if(r==n-1 && c==n-1) return true;

            for(int i=0;i<4;i++){
                int nr=r+del_r[i];
                int nc=c+del_c[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0){
                    if(dis[nr][nc]>=mid){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
        }

        return false;

    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1) return 0;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));

        vector<vector<int>> dis(n,vector<int>(n,0));
        

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int level=0;

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                dis[r][c]=level;

                for(int i=0;i<4;i++){
                    int nr=r+del_r[i];
                    int nc=c+del_c[i];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
            level++;
        }

        int l=0,h=400;
        int res;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check_path(dis,mid)==true){
                res=mid;
                l=mid+1;
            }
            else h=mid-1;
        }

        return res;
    }
};