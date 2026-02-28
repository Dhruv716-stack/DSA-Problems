
class Disjointset
{
    vector<int> rank, size, parent;
    public:
    Disjointset(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findUparent(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findUparent(parent[node]);
    }

    void union_by_size(int u, int v)
    {
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((stones[i][0]==stones[j][0]) || (stones[i][1]==stones[j][1]))
                {
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<pair<int,int>> edges;
        for(int i=1;i<=n;i++)
        {
            for(auto &it:adj[i])
            {
                edges.push_back({i,it});
            }
        }

        Disjointset ds(n);
        int cnt=0;
        for(auto &it:edges)
        {
            int u=it.first;
            int v=it.second;
            if(ds.findUparent(u)!=ds.findUparent(v))
            {
                cnt++;
                ds.union_by_size(u,v);
            }
        }
        return cnt;
    }
};