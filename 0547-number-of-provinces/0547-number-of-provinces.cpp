class Solution {
public:
    void bfs(vector<vector<int>>& adj,int node,vector<int>&vis)
    {
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int node1=q.front();
            q.pop();
            vis[node1]=1;
            for (int j = 0; j < adj.size(); j++) {
            if (adj[node1][j] == 1 && !vis[j]) {
                vis[j] = 1;
                q.push(j);
            }
        }
        }
        return;

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);
        int cnt=0;
        for(int i=0;i<vis.size();i++)
        {
            if(!vis[i])
            {
                bfs(isConnected,i,vis);
                vis[i]=1;
                cnt++;
            }
            //cnt++;

        }
        return cnt;
    }
};