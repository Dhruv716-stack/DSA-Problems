class Solution {
public:
    int solve(int i, int j,int k,vector<vector<int>>&coins, vector<vector<vector<int>>>&dp)
    {
        if(i<0 || j<0) return -1e8;
        if(i==0 && j==0)
        {
            if(k>0 && coins[0][0]<0) return 0;
            else return coins[0][0];
        }
        if(dp[i][j][k]!=-1e8) return dp[i][j][k];
        int p1=-1e8,p2=-1e8;
        if(coins[i][j]>=0)
        {
            p1=coins[i][j]+solve(i-1,j,k,coins,dp);
            p2=coins[i][j]+solve(i,j-1,k,coins,dp);
        }
        else if(coins[i][j]<0)
        {
            int take1=-1e8,take2=-1e8,skip1=-1e8,skip2=-1e8;
            take1=coins[i][j]+solve(i-1,j,k,coins,dp);
            take2=coins[i][j]+solve(i,j-1,k,coins,dp);
            if(k>0)
            {
                skip1=solve(i-1,j,k-1,coins,dp);
                skip2=solve(i,j-1,k-1,coins,dp);
            }
            p1=max(take1,skip1);
            p2=max(take2,skip2);
        }
        return dp[i][j][k]=max(p1,p2);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,-1e8)));
        return solve(m-1,n-1,2,coins,dp);
    }
};