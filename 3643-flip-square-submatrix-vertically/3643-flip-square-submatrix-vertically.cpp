class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int er=x+k-1;
        int ec=y+k-1;
        for(int i=x;i<=er;i++)
        {
            for(int j=y;j<=ec;j++)
            {
                swap(grid[i][j],grid[er][j]);
            }
            er--;
        }
        return grid;
    }
};