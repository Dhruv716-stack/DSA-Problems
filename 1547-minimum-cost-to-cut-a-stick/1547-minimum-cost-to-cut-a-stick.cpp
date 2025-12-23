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
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return solve(1,m-2,cuts,dp);
    }
};