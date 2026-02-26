class Solution {
public:
    typedef long long ll;
    ll solve(int i, int j1, int j2, vector<vector<int>>&grid,vector<vector<vector<ll>>>&dp)
    {
        int m=grid[0].size();
        int n=grid.size();
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
        if(i==n-1)
        {
            if(j1==j2) return grid[i][j1];
            else return (grid[i][j1]+grid[i][j2]);
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        ll maxi=0;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                if(j1==j2) maxi=max(maxi,grid[i][j1]+solve(i+1,j1+dj1,j2+dj2,grid,dp));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(i+1,j1+dj1,j2+dj2,grid,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m,vector<ll>(m,-1)));
        return solve(0,0,m-1,grid,dp);
    }
};