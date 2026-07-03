class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dis(m,vector<int>(n,100));
        deque<pair<int,pair<int,int>>> dq;

        if(grid[0][0]==1) dq.push_back({grid[0][0],{0,0}});
        else dq.push_front({grid[0][0],{0,0}});

        vector<int> del_r={0,1,0,-1};
        vector<int> del_c={1,0,-1,0};

        while(!dq.empty()){
            auto [d,coor]=dq.front();
            auto [r,c]=coor;
            dq.pop_front();

            for(int i=0;i<4;i++){
                int nr=r+del_r[i];
                int nc=c+del_c[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if(grid[nr][nc]+d<dis[nr][nc]){
                        dis[nr][nc]=d+grid[nr][nc];
                        if(grid[nr][nc]==1) dq.push_back({dis[nr][nc],{nr,nc}});
                        else dq.push_front({dis[nr][nc],{nr,nc}});
                    }
                }
            }
        }

        if(dis[m-1][n-1]<health) return true;
        return false;
    }
};