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
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        int x=n-1;
        int ans=solve(s1,s2,x,m-1,dp);
        return ans;
        
    }
};