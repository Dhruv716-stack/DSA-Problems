class Solution {
public:

    bool dfs(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;

        for(auto &it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis)==true) return true;
            }

            else if(pathvis[it]==1){
                return true;
            }
        }

        pathvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses+1);
        vector<int> vis(numCourses+1,0),pathvis(numCourses+1,0);

        for(auto &it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true) return false;
            }
        }

        return true;
    }
};