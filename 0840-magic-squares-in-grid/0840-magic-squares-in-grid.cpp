class Solution {
public:
    bool is_magic(int r, int c, vector<vector<int>> &grid)
    {
        unordered_set<int>st;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[r+i][j+c]>9 || grid[i+r][j+c]<1 || st.find(grid[r+i][j+c])!=st.end())
                {
                    return false;
                }
                else st.insert(grid[i+r][j+c]);
            }
        }
        unordered_map<int,int> mp;
        int sum_d1=grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2];
        int sum_d2=grid[r][c+2]+grid[r+2][c]+grid[r+1][c+1];
        mp[sum_d1]++;
        mp[sum_d2]++;
        for(int i=0;i<3;i++)
        {
            int sum_r=0;
            int sum_c=0;
            for(int j=0;j<3;j++)
            {
                sum_r+=grid[i+r][j+c];
                sum_c+=grid[j+r][i+c];
            }
            mp[sum_r]++;
            mp[sum_c]++;
        }
        if(mp[sum_d1]!=8) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=m-3;j++)
            {
                if(is_magic(i,j,grid)==true) cnt++;
            }
        }
        return cnt; 
    }
};