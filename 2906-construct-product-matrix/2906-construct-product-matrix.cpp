class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        const int M=12345;
        long long suff=1;
        vector<vector<int>> p(m,vector<int>(n));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                p[i][j]=suff;
                suff=(suff*grid[i][j])%M;
            }
        }
        long long pre=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                p[i][j]=(p[i][j]*pre)%M;
                pre=(pre*grid[i][j])%M;
            }
        }
        return p;
    }
};