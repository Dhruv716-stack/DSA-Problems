class Solution {
public:
    typedef long long ll;
    ll total=0;
    bool check_hori(vector<vector<int>>&grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        ll top=0,bottom=0;
        ll diff=0;
        unordered_set<ll> st;
        for(int i=0;i<=m-2;i++)
        {
            for(int j=0;j<n;j++)
            {
                st.insert(grid[i][j]);
                top+=grid[i][j];
            }
            bottom=total-top;
            diff=top-bottom;
            if(diff==0) return true;
            if(diff==1LL*grid[0][0]) return true;
            if(diff==1LL*grid[0][n-1]) return true;
            if(diff==1LL*grid[i][0]) return true;
            if(i>0 && n>1 && (st.count(diff))) return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                total+=grid[i][j];
            }
        }
        //Horizontal grid check cuts from top
        if (check_hori(grid)) return true;

        // Horizontal grid check cuts from bottom
        reverse(grid.begin(),grid.end());
        if(check_hori(grid)) return true;

        reverse(grid.begin(),grid.end());
        //Vertical grid check using horizontal method
        //By taking transpose of matrix

        vector<vector<int>> transpose(n,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                transpose[j][i]=grid[i][j];
            }
        }

        //Vertical grid check cuts from top
        if (check_hori(transpose)) return true;

        //Vertical grid check cuts from bottom
        reverse(transpose.begin(),transpose.end());
        if (check_hori(transpose)) return true;

        return false;
    }
};