class Solution {
public:
    bool is_palin(int i,int j,string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, string &s,vector<int> &dp)
    {
        int n=s.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int min_cost=1e7+3;
        for(int j=i;j<n;j++)
        {
            if(is_palin(i,j,s)==true)
            {
                int cost=1+solve(j+1,s,dp);
                min_cost=min(min_cost,cost);
            }
        }
        return dp[i]=min_cost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp)-1;

    }
};