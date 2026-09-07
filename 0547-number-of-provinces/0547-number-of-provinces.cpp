class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj, vector<int>&vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            int u=i+1;
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[u].push_back(j+1);
                }
            }
        }

        vector<int> vis(n+1,0);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt;
    }
};