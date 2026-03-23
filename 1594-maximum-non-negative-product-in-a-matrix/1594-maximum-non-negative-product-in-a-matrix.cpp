class Solution {
public:
    typedef long long ll;
    const int M=1e9+7;
    vector<vector<pair<ll,ll>>> dp; //dp storting pairs of maxval and minval
    /*pair<ll,ll> solve(int i, int j, vector<vector<int>>&grid)
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
    }*/
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp=vector<vector<pair<ll,ll>>> (m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX}));
        dp[m-1][n-1]=make_pair(grid[m-1][n-1],grid[m-1][n-1]);

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1) continue;

                ll maxval=LLONG_MIN,minval=LLONG_MAX;
                //Down
                if(i+1<m)
                {auto [dmax,dmin]=dp[i+1][j];
                maxval=max({maxval,grid[i][j]*dmax,grid[i][j]*dmin});
                minval=min({minval,grid[i][j]*dmax,grid[i][j]*dmin});
                }

                //Right
                if(j+1<n)
                {
                auto [rmax,rmin]=dp[i][j+1];
                maxval=max({maxval,grid[i][j]*rmax,grid[i][j]*rmin});
                minval=min({minval,grid[i][j]*rmax,grid[i][j]*rmin});
                }

                dp[i][j]=make_pair(maxval,minval);
            }
        }
        auto [mx,mn]=dp[0][0];
        return mx<0 ? -1:(mx%M);
    }
};