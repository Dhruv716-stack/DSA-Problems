class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis,int node)
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(adj,vis,pathvis,it)==true) return true;
            }
            else if(pathvis[it]) return true;
        }
        pathvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>> adj(V);
        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,pathvis,i)==true) return false;
            }
        }
        return true;
    }
};