class Solution {
public:
    int solve(int ind, int buy, vector<int>&arr,vector<vector<vector<int>>>&dp,int t)
    {
        int n=arr.size();
        if(ind==n|| t==0) return 0;
        if(dp[ind][buy][t]!=-1) return dp[ind][buy][t];
        long long profit=0;
                if(buy==1)
                {
                    profit=max((-arr[ind]+solve(ind+1,0,arr,dp,t)),solve(ind+1,1,arr,dp,t));
                }
                else
                {
                    profit=max((arr[ind]+solve(ind+1,1,arr,dp,t-1)),solve(ind+1,0,arr,dp,t));
                }

            
        return dp[ind][buy][t]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,prices,dp,2);
    }
};