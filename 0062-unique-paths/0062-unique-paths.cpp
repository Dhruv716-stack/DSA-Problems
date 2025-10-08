class Solution {
public:
    /*int solve(int m,int n,int r,int c,vector<vector<int>>&dp)
    {
        if(r==m-1 &&c==n-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int l=0,ri=0;
        if(r>=0 && r<m && c>=0 && c<n)
        {
            l=solve(m,n,r+1,c,dp);
            ri=solve(m,n,r,c+1,dp);
        }

        return dp[r][c]=l+ri;
    }*/
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                int l=0,r=0;
                if(i==0 && j==0) temp[j]=1;
                else
                {
                   int up=0;
                   int left=0;
                   up=prev[j];
                   if(j>0) left=temp[j-1];
                   temp[j]=up+left;
                }
                
                
            }
            prev=temp;
        }
        return prev[n-1];
    }
};