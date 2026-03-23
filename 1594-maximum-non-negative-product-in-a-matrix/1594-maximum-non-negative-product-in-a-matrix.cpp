class Solution {
public:
    typedef long long ll;
    const int M=1e9+7;
    vector<vector<pair<ll,ll>>> dp; //dp storting pairs of maxval and minval
    pair<ll,ll> solve(int i, int j, vector<vector<int>>&grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i==m-1 && j==n-1) return {grid[i][j],grid[i][j]};
        if(dp[i][j]!=make_pair(LLONG_MIN,LLONG_MAX))
        {
            return dp[i][j];
        }

        ll maxval=LLONG_MIN;
        ll minval=LLONG_MAX;

        //Down
        if(i+1<m)
        {auto [dmax,dmin]=solve(i+1,j,grid);
        maxval=max({maxval,grid[i][j]*dmax,grid[i][j]*dmin});
        minval=min({minval,grid[i][j]*dmax,grid[i][j]*dmin});
        }

        //Right
        if(j+1<n)
        {
            auto [rmax,rmin]=solve(i,j+1,grid);
            maxval=max({maxval,grid[i][j]*rmax,grid[i][j]*rmin});
            minval=min({minval,grid[i][j]*rmax,grid[i][j]*rmin});
        }

        return dp[i][j]={maxval,minval};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp=vector<vector<pair<ll,ll>>> (m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX}));
        auto [mx,mn]=solve(0,0,grid);
        return mx<0 ? -1:(mx%M);
    }
};