class Disjointset{
    
    public:
    vector<int> rank, parent,size;
    Disjointset(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n;i++)
        {
            parent[i] = i;
        }
    }

    int findUparent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node] = findUparent(parent[node]);  //Path Compression
    }

    void unionbyrank(int u,int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if(ulp_u==ulp_v)
            return;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbysize(int u,int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if(ulp_u==ulp_v)
            return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    
    int makeConnected(int n, vector<vector<int>>& connections) {
      int cntextra=0;
      Disjointset ds(n);
      for(auto it:connections)
      {
        int u=it[0];
        int v=it[1];
        if(ds.findUparent(u)==ds.findUparent(v)) cntextra++;
        else ds.unionbysize(u,v);

      }
      int cntc=0;
      for(int i=0;i<n;i++)
      {
        if(ds.parent[i]==i) cntc++;
      }
      if(cntextra>=cntc-1) return cntc-1;
      return -1;
    }
};