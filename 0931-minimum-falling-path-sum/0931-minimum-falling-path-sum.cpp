class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //vector<vector<long long>> dp(n+1,vector<long long>(n+1,1e7));
        vector<int> front(n,0),curr(n,0);
        long long mini=INT_MAX;
        for(int i=0;i<n;i++) front[i]=matrix[n-1][i];

        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                long long p1=1e7,p2=1e7,p3=1e7;
                if(j+1<n)p1=1LL*matrix[i][j]+front[j+1];
                p2=1LL*matrix[i][j]+front[j];
               if(j-1>=0) p3=1LL*matrix[i][j]+front[j-1];
                curr[j]=min({p1,p2,p3});
            }
            front=curr;
        }

        for(int i=0;i<n;i++)
        {
            mini= min(mini,1LL*front[i]);
        }
        return mini;
    }
};