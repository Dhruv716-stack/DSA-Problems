class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int node=p.second;
            int dis=p.first;
            for(auto it:adj[node])
            {
                int adj_node=it.first;
                int edgewt=it.second;
                if(edgewt+dis<dist[adj_node])
                {
                    dist[adj_node]=edgewt+dis;
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        int mx=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,dist[i]);
            if(mx==INT_MAX) return -1;
        }
        //if(mx==INT_MAX) return -1;
        return mx;

    }
};