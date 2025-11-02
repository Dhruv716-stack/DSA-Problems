class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0) prev[t]=t/coins[0];
            else prev[t]=1e9;
        }

        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                int not_take=prev[t];
                int take=1e9;
                if(coins[i]<=t) take=1+curr[t-coins[i]];
                curr[t]=min(take,not_take);
            }
            prev=curr;
        }
        if(prev[amount]==1e9) return -1;
        return prev[amount];
    }
};