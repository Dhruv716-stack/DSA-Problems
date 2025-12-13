class Solution {
public:
    int solve(int ind,int buy, vector<int>&arr,vector<vector<int>>&dp,int profit)
    {
        int n=arr.size();
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==1)
        {
            profit=max((-arr[ind]+solve(ind+1,0,arr,dp,profit)),solve(ind+1,1,arr,dp,profit));
        }
        else
        {
            profit=max(arr[ind]+solve(ind+2,1,arr,dp,profit),solve(ind+1,0,arr,dp,profit));
        }
        return dp[ind][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp,0);
    }
};