class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int d=dp[i+1][j];
                int dl=INT_MAX,dr=INT_MAX;
                if(j>0) dl=dp[i+1][j-1];
                if(j<n-1) dr=dp[i+1][j+1];
                int min_next=min({d,dr,dl});
                if(min_next==INT_MAX) dp[i][j]=min_next;
                else
                {
                    dp[i][j]=min_next+matrix[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[0][i]);

        }
        return ans;
    }
};