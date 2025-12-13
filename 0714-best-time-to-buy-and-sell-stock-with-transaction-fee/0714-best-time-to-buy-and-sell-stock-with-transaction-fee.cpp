class Solution {
public:
    int solve(vector<int>&arr,int ind,int buy,vector<vector<int>>&dp,int profit,int fee)
    {
        int n=arr.size();
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==1)
        {
            profit=max((solve(arr,ind+1,0,dp,profit,fee)-arr[ind]),solve(arr,ind+1,1,dp,profit,fee));
        }
        else
        {
            profit=max((solve(arr,ind+1,1,dp,profit,fee)+arr[ind]-fee),solve(arr,ind+1,0,dp,profit,fee));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp,0,fee);
    }
};