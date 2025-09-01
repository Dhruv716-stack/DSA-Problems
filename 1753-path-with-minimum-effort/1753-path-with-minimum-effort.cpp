class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //queue<pair<pair<pair<int,int>,int>,int>> pq;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({0,{0,0}});
        int del_r[4]={-1,0,1,0};
        int del_c[4]={0,1,0,-1};
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        int ans=0;
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int r=p.second.first;
            int c=p.second.second;
            int req=p.first;
            if(r==m-1 && c==n-1)
            {
                ans=req;
                break;
            }
            for(int i=0;i<4;i++)
            {
                int nr=r+del_r[i];
                int nc=c+del_c[i];
                if(nr>=0 && nr<m &&nc>=0 && nc<n)
                {
                    int diff=abs(grid[nr][nc]-grid[r][c]);
                    int neweff=max(req,diff);
                    if(neweff<dist[nr][nc])
                    {
                        dist[nr][nc]=neweff;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return ans;
    }
};