class Solution {
public:
    int M=int(1e9) +7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //vector<int> vis(n,0);
        vector<long long> dist(n,LLONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int node=p.second;
            long long dis=p.first;
            if (dis > dist[node]) continue;
            for(auto it:adj[node])
            {
                long long adj_node=it.first;
                long long edgewt=it.second;
                if(dis+edgewt<dist[adj_node])
                {
                    dist[adj_node]=dis+edgewt;
                    pq.push({dist[adj_node],adj_node});
                    ways[adj_node]=ways[node];
                }
                else if(dis+edgewt == dist[adj_node])
                {
                    ways[adj_node]=(ways[adj_node]+ways[node])%M;
                }
            }
        }
        return int((ways[n-1])%M);
        

    }
};