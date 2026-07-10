class DisjointSet{
    public:
    vector<int> size,par;
    DisjointSet(int n){
        size.resize(n+1,1);
        par.resize(n+1);

        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }

    int findUpar(int node){
        if(node==par[node]) return node;
        return par[node]=findUpar(par[node]);
    }

    void union_by_size(int u, int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }

        else{
            par[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
           DisjointSet ds(n);
           vector<bool> ans;

           for(int i=0;i<n-1;i++){
            int l=i+1;
            int h=n-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if((nums[mid]-nums[i])<=maxDiff){
                    ds.union_by_size(i,mid);
                    l=mid+1;
                }
                else h=mid-1;
            }
           }

           for(auto &it:queries){
            int u=it[0];
            int v=it[1];
            int ulp_u=ds.findUpar(u);
            int ulp_v=ds.findUpar(v);
            bool flag=(ulp_u==ulp_v);
            ans.push_back(flag);
           }

           return ans;
    }
};