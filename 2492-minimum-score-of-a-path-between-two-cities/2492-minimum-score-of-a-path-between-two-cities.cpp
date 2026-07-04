class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n+1,1e9);
        dis[1]=0;
        pq.push({0,1});

        int mn=INT_MAX;
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();

            if(d==1e9) continue;

            for(auto &it:adj[node]){
                int adjnode=it.first;
                int edwt=it.second;
                if(edwt<mn) mn=edwt;
                if(d+edwt<dis[adjnode]){
                    dis[adjnode]=d+edwt;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }

        return mn;

    }
};