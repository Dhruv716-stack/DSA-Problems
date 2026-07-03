class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dis(m,vector<int>(n,100));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({grid[0][0],{0,0}});
        dis[0][0]=grid[0][0];

        vector<int> del_r={0,1,0,-1};
        vector<int> del_c={1,0,-1,0};

        while(!pq.empty()){
            auto [d,coor]=pq.top();
            auto [r,c]=coor;
            pq.pop();

            for(int i=0;i<4;i++){
                int nr=r+del_r[i];
                int nc=c+del_c[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if(grid[nr][nc]+d<dis[nr][nc]){
                        dis[nr][nc]=d+grid[nr][nc];
                        pq.push({dis[nr][nc],{nr,nc}});
                    }
                }
            }
        }

        if(dis[m-1][n-1]<health) return true;
        return false;
    }
};