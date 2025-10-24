class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> front(n,0);
        vector<int> curr(n,0);
        for(int j=0;j<n;j++)
        {
            front[j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int d=front[j];
                int dl=INT_MAX,dr=INT_MAX;
                if(j>0) dl=front[j-1];
                if(j<n-1) dr=front[j+1];
                int min_next=min({d,dr,dl});
                if(min_next==INT_MAX) curr[j]=min_next;
                else
                {
                    curr[j]=min_next+matrix[i][j];
                }
            }
            front=curr;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,front[i]);

        }
        return ans;
    }
};