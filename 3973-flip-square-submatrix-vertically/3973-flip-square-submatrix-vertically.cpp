class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m=grid.size();
        int n=grid[0].size();
        for(int j=0;j<k/2;j++)
        {
            for(int i=0;i<k;i++)
            {
                if((x+k-1-j)<m &&x+j<m && y+i<n) 
                {swap(grid[x+j][y+i],grid[x-j+k-1][y+i]);}
            }
        }
        return grid;
    }
};