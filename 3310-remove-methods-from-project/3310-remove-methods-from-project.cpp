class Solution {
public:
    vector<int> cant_remove;
    bool flag=false;

    void dfs1(int node, vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfs1(it,adj,vis);
            }
        }
        return;
    }

    void dfs2(int node,vector<vector<int>>&adj,vector<int>&vis, vector<int>&sus){
        vis[node]=1;
        if(!sus[node]){
        for(auto &it:adj[node]){
            if(sus[it]==1){
                    flag=true;
                }
            if(!vis[it]){
                dfs2(it,adj,vis,sus);
            }
        }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &it:invocations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }

        vector<int> sus(n,0),vis(n,0);
        vector<int> ans;
        dfs1(k,adj,sus);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs2(i,adj,vis,sus);
            }
        }

        if(flag==true){
            for(int i=0;i<n;i++) ans.push_back(i);
        }
        else{
            for(int i=0;i<n;i++){
                if(sus[i]==0) ans.push_back(i);
            }
        }
        return ans;

    }
};