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
    bool isvalid(int r, int c, int ar, int ac, int m)
    {
        return(r>=0 && r<m && c>=0 && c<m && ar>=0 && ar<m && ac>=0 && ac<m);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        Disjointset ds(m*n);
        int ans=-1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                int r=i,c=j;
                vector<int> delr={-1,0,1,0};
                vector<int> delc={0,1,0,-1};
                for(int ind=0;ind<4;ind++)
                {
                    int ar=r+delr[ind];
                    int ac=c+delc[ind];
                    if(isvalid(r,c,ar,ac,m))
                    {
                    int node=r*m+c;
                    int adj_node=ar*m+ac;
                    if(grid[ar][ac]==1)
                    {
                        ds.union_by_size(node,adj_node);
                    }
                    }
                }
            }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int r=i,c=j;
                if(grid[i][j]==0)
                {
                vector<int> delr={-1,0,1,0};
                vector<int> delc={0,1,0,-1};
                set<int> st;
                for(int ind=0;ind<4;ind++)
                {
                    int ar=r+delr[ind];
                    int ac=c+delc[ind];
                    if(isvalid(r,c,ar,ac,m))
                    {
                    int node=r*m+c;
                    int adj_node=ar*m+ac;
                    if(grid[ar][ac]==1)
                    {
                        int parent=ds.findUparent(adj_node);
                        st.insert(parent);
                    }
                }
                int total=1;
                for(auto &it:st)
                {
                    total+=ds.size[it];
                }
                ans=max(ans,total);
            }
        }
    }
    }
    if(ans==-1) return m*m;
    return ans;
    }
};