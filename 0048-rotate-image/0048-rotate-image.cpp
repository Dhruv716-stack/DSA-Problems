class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }

        int i=0,j=m-1;
        while(i<=j)
        {
            for(int k=0;k<n;k++)
            {
                swap(mat[k][i],mat[k][j]);
            }
            i++;
            j--;
        }
        return;
    }
};