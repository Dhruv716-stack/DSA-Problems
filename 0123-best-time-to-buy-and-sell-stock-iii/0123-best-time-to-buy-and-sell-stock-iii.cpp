class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        int profit=0;
        //dp[n][0][0]=dp[n][1][0]=0;

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int t=1;t<=2;t++)
                {
                    if(buy==1)
                {
                    profit=max((-arr[ind]+after[0][t]),after[1][t]);
                }
                else
                {
                    profit=max((arr[ind]+after[1][t-1]),after[0][t]);
                }
                curr[buy][t]=profit;
                }
            }
            after=curr;
        }



        return after[1][2];
    }
};