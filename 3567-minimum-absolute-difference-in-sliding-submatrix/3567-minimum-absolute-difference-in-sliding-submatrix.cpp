class Solution {
public:
    int is_min(vector<vector<int>> &grid,int i1, int j1 , int i2, int j2)
    {
        int mn=INT_MAX;
        set<int> st;
        for(int i=i1;i<=i2;i++)
        {
            for(int j=j1;j<=j2;j++)
            {
                st.insert(grid[i][j]);
            }
        }
        auto prev=st.begin();
        auto curr=next(prev);
        if(st.size()==1) return 0;
        while(curr!=st.end())
        {
            mn=min(mn,(abs(*prev-*curr)));
            prev=curr;
            curr++;
        }
        return mn;

    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i<=n-k;i++)
        {
            for(int j=0;j<=m-k;j++)
            {
                int x=is_min(grid,i,j,i+k-1,j+k-1);
                ans[i][j]=x;
            }
        }
        return ans;

    }
};