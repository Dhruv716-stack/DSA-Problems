class Solution {
public:
    int solve(vector<vector<int>>&tri,int i,int j,vector<vector<int>>&dp)
    {
        int m=tri.size();
        if(i==m-1) return tri[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int d=INT_MAX,dg=INT_MAX;
        d=tri[i][j]+solve(tri,i+1,j,dp);
        dg=tri[i][j]+solve(tri,i+1,j+1,dp);
        return dp[i][j]=min(d,dg);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<int> front(n,0);
        vector<int> curr(n,0);
        for(int i=0;i<n;i++)
        {
            front[i]=triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int d=triangle[i][j]+front[j];
                int dg=triangle[i][j]+front[j+1];
                curr[j]=min(d,dg);
            }
            front=curr;
        }
        return front[0];

    }
};