class Solution {
public:
    /*int solve(vector<int>&arr,int ind,int buy,vector<vector<int>>&dp,int profit,int fee)
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
    }*/
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        //vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int>f(2,0),curr(2,0);
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy==1) profit=max((-prices[ind]+f[0]),f[1]);
                else profit=max((prices[ind]-fee+f[1]),f[0]);
                curr[buy]=profit;
            }
            f=curr;
        }
        return f[1];
    }
};