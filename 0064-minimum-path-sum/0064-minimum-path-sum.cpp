class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {   vector<int> curr(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    curr[j]=grid[0][0];
                    continue;
                }
                int p1=INT_MAX,p2=INT_MAX;
                if(i>0) p1=grid[i][j]+prev[j];
                if(j>0) p2=grid[i][j]+curr[j-1];
                curr[j]=min(p1,p2);
            }
            prev=curr;
        }
        return prev[n-1];
    }
};