class Disjointset
{
    public:
    vector<int> rank, size, parent;
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
    int maxActivated(vector<vector<int>>& points) {
        int n=points.size();
        Disjointset ds(n);
        unordered_map<int,int> mpx,mpy;
        for(int i=0;i<n;i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            if(mpx.count(x)) ds.union_by_size(i,mpx[x]);
            else mpx[x]=i;

            if(mpy.count(y)) ds.union_by_size(i,mpy[y]);
            else mpy[y]=i;
        }

        vector<int> cmp;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i) cmp.push_back(ds.size[i]);
        }
        sort(cmp.begin(),cmp.end(),greater<int>());
        if(cmp.size()>1) return cmp[0]+cmp[1]+1;
        else if(cmp.size()==1) return cmp[0]+1;
        else return 1;
    }
};