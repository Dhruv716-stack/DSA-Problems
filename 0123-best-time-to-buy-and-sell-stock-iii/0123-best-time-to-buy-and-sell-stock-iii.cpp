class Solution {
public:
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