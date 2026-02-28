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
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int cnt=0;
        for(auto &it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findUparent(u)!=ds.findUparent(v))
            {
                cnt++;
                ds.union_by_size(u,v);
            }
        }
        int s=connections.size();
        int c1=s-cnt;
        int c2=n-(cnt+1);
        if(c2>c1) return -1;
        return c2; 
    }
};