class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, vector<int>&nums){
        int n=nums.size();
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take_i=nums[i]-solve(i+1,j,nums);
        int take_j=nums[j]-solve(i,j-1,nums);
        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,n-1,piles)>0;
    }
};