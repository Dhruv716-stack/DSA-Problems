class Solution {
public:
    bool is_palin(int i, int j, string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    /*int solve(int i, string &s,vector<int>&dp)
    {
        int n=s.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int min_cost=INT_MAX;
        for(int j=i;j<n;j++)
        {
            int take=INT_MAX;
            if(is_palin(i,j,s)==true)
            {
                int cost=1+solve(j+1,s,dp);
                take=min(take,cost);
            }
        min_cost=min({take,min_cost});
        }
        return dp[i]=min_cost;
    }*/
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        vector<int> front(n+1,0),curr(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int min_cost=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(is_palin(i,j,s)==true)
                {
                    int cost=1+front[j+1];
                    min_cost=min(min_cost,cost);
                }
            }
            curr[i]=min_cost;
            front=curr;
        }
        return front[0]-1;
    }
};