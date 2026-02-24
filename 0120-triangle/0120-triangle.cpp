class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int n1=triangle[n-1].size();
        vector<int> front(n1,0);
        for(int j=0;j<n1;j++) front[j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--)
        {
            vector<int> curr(i+1,0);
            for(int j=i;j>=0;j--)
            {
                long long p1=INT_MAX,p2=INT_MAX;
                p1=1LL*triangle[i][j]+front[j];
                p2=1LL*triangle[i][j]+front[j+1];
                curr[j]=min(p1,p2);
            }
            front=curr;
        }
        return front[0];
    }
};