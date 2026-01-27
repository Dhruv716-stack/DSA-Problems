class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<int> dis(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[0]=0;
        pq.push({dis[0],0});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &it:adj[node])
            {
                int adjnode=it.first;
                int edwt=it.second;
                if(d+edwt<(dis[adjnode]))
                {
                    dis[adjnode]=d+edwt;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        if(dis[n-1]==1e9) dis[n-1]=-1;
        return dis[n-1];
    }
};