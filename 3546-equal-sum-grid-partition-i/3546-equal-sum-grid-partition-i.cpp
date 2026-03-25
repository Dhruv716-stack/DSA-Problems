class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>> p(m+1,vector<long long>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                p[i][j]=p[i-1][j]+p[i][j-1]+1LL*grid[i-1][j-1]-p[i-1][j-1];
            }
        }

        long long t=p[m][n];
        for(int i=1;i<m;i++)
        {
            if(p[i][n]==(t-p[i][n])) return true;
        }
        for(int j=1;j<n;j++)
        {
            if(p[m][j]==(t-p[m][j])) return true;
        }
        return false;
    }
};