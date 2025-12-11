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
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        int profit=0;
        dp[n][0][0]=dp[n][1][0]=0;

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int t=1;t<=2;t++)
                {
                    if(buy==1)
                {
                    profit=max((-arr[ind]+dp[ind+1][0][t]),dp[ind+1][1][t]);
                }
                else
                {
                    profit=max((arr[ind]+dp[ind+1][1][t-1]),dp[ind+1][0][t]);
                }
                dp[ind][buy][t]=profit;
                }
            }
        }



        return dp[0][1][2];
    }
};