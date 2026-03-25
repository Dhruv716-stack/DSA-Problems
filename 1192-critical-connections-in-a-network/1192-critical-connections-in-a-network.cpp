class Solution {
private:
int timer=1;
private:
    void dfs(int node, int parent,vector<vector<int>>&adj, vector<int>&vis, vector<int>&tin, vector<int>&low, vector<vector<int>>&bri)
    {
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto &it:adj[node])
        {
            if(it==parent) continue;
            if(vis[it]==0)
            {
                dfs(it,node,adj,vis,tin,low,bri);
                low[node]=min(low[node],low[it]);
                // Checking if it---node is forming bridge or not
                if(low[it]>tin[node]) bri.push_back({it,node});
            }
            else low[node]=min(low[node],low[it]);
        }
        return;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &it:connections)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        vector<vector<int>> bri;
        vector<int> tin(n),low(n);
        dfs(0,-1,adj,vis,tin,low,bri);
        return bri;
    }
};