class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});
        while(!pq.empty())
        {
            auto p=pq.front();
            pq.pop();
            int node=p.second.first;
            int cost=p.second.second;
            int stops=p.first;
            if(stops>k) continue;
            for(auto it:adj[node])
            {
                int edgewt=it.second;
                int adj_node=it.first;
                if(cost+edgewt<dist[adj_node] && stops<=k)
                {
                    dist[adj_node]=cost+edgewt;
                    pq.push({stops+1,{adj_node,dist[adj_node]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};