class Solution {
public:

    int solve(string &s1, string&s2, int i, int j, vector<vector<int>>& dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=INT_MAX) return dp[i][j]; 
        if(s1[i]==s2[j]) return dp[i][j]=solve(s1,s2,i-1,j-1,dp);
           int op=1+solve(s1,s2,i-1,j-1,dp);
           int del=1+solve(s1,s2,i-1,j,dp);
           int ins=1+solve(s1,s2,i,j-1,dp);
           return dp[i][j]=min({op,ins,del});
        
    }
    
    int minDistance(string word1, string word2) {
        string s1=word1;
        string s2=word2;
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));

        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=1;j<=m;j++) dp[0][j]=j;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    int del=1+dp[i-1][j];
                    int ins=1+dp[i][j-1];
                    int re=1+dp[i-1][j-1];
                    dp[i][j]=min({del,ins,re});
                }
            }
        }
        return dp[n][m];
        
    }
};