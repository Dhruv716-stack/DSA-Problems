class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<long long>> pf(m+1,vector<long long>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                pf[i][j]=1LL*mat[i-1][j-1]+1LL*pf[i-1][j]+1LL*pf[i][j-1]-1LL*pf[i-1][j-1];
            }
        }
        int maxi=0;
        int l=min(m,n);
        for(int k=l-1;k>=1;k--)
        {
            for(int i=0;i<(m-k);i++)
            {
                for(int j=0;j<(n-k);j++)
                {
                    
                    long long ans=pf[i+1+k][j+1+k]-pf[i][j+k+1]-pf[i+k+1][j]+pf[i][j];
                    if(ans<=1LL*threshold)
                    {
                        maxi=max(maxi,k+1);
                        return maxi;
                    }
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]<=threshold)
                {
                    maxi=max(1,maxi);
                    return maxi;
                }
            }
        }
        return maxi;
    }
};