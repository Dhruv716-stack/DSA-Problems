class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>> adj(V);
        int cnt=0;
        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> indegree(V);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        vector<int> v;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            v.push_back(node);
            cnt++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(cnt==V) return v;
        return {};
    }
};