class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> p(m+1,vector<int>(n+1,0));
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                p[i][j]=grid[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
                if(p[i][j]<=k) cnt++;
            }
        }
        return cnt;

    }
};