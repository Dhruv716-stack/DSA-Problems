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
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        vector<int> f2(2,0),f1(2,0),curr(2,0);
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy==1)
                {
                    profit=max((-prices[ind]+f1[0]),f1[1]);
                }
                else
                {
                    profit=max((prices[ind]+f2[1]),f1[0]);
                }
                curr[buy]=profit;
            }
            f2=f1;
            f1=curr;
        }
        return f1[1];
    }
};