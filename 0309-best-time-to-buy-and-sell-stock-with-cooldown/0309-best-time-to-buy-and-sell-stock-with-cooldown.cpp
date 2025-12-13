class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
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