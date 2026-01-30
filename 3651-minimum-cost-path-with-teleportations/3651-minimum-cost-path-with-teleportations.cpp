class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1e8));
        int mx=INT_MIN;
        dp[m-1][n-1]=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) mx=max(mx,grid[i][j]);
        }
        vector<int> tele(mx+1,1e8);
        for(int t=0;t<=k;t++)
        {
            for(int i=m-1;i>=0;i--)
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(i+1<m)
                    {
                        dp[i][j]=min(dp[i][j],dp[i+1][j]+grid[i+1][j]);
                    }
                    if(j+1<n)
                    {
                        dp[i][j]=min(dp[i][j],dp[i][j+1]+grid[i][j+1]);
                    }
                    if(t>0)
                    {
                        dp[i][j]=min(dp[i][j],tele[grid[i][j]]);
                    }
                }
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    tele[grid[i][j]]=min(tele[grid[i][j]],dp[i][j]);
                }
            }

            //Prefix minimum calculation for tele array
            for(int i=1;i<tele.size();i++)
            {
                tele[i]=min(tele[i],tele[i-1]);
            }
        }
        return dp[0][0];  
    }
};