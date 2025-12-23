class Solution {
public:
    int solve(int i, int j,vector<int>&cuts,vector<vector<int>>&dp )
    {
        int m=cuts.size();
        int mini=INT_MAX;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i;ind<=j;ind++)
        {
            int cost=cuts[j+1]-cuts[i-1]+solve(i,ind-1,cuts,dp)+solve(ind+1,j,cuts,dp);
            mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i>j) dp[i][j]=0;
            }
        }
        for(int i=m-2;i>=1;i--)
        {
            for(int j=i;j<=m-2;j++)
            {
                long long mini=INT_MAX;
                for(int ind=i;ind<=j;ind++)
                {
                    long long tc=cuts[j+1]-1LL*cuts[i-1]+1LL*dp[i][ind-1]+1LL*dp[ind+1][j];
                    mini=min(mini,tc);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][m-2];
    }
};