class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,INT_MAX));
        for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==n-1) continue;
                long long p1=INT_MAX,p2=INT_MAX;
                p1=1LL*triangle[i][j]+dp[i+1][j];
                p2=1LL*triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(p1,p2);
            }
        }
        return dp[0][0];
    }
};