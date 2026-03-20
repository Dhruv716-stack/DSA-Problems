
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
        int mx_row=0,mx_col=0;
        for(auto &it:stones)
        {
            mx_row=max(mx_row,it[0]);
            mx_col=max(mx_col,it[1]);
        }

        Disjointset ds(mx_row+mx_col+1);
        unordered_map<int,int> mp;
        for(auto &it:stones)
        {
            int r=it[0];
            int c=it[1]+mx_row+1;
            ds.union_by_size(r,c);
            mp[r]=1;
            mp[c]=1;
        }

        int cnt=0;
        for(auto &it:mp)
        {
            if(ds.findUparent(it.first)==it.first)
            {
                cnt++;
            }
        }

        return n-cnt;
    }
};