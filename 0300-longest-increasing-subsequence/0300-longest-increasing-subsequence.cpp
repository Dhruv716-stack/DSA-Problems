class Solution {
public:
    int solve(int ind, int prev_i,vector<int>&nums,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(ind==n) return 0;
        if(dp[ind][prev_i+1]!=-1) return dp[ind][prev_i+1];
        int not_take=solve(ind+1,prev_i,nums,dp);
        int take=0;
        if(prev_i==-1 || nums[ind]>nums[prev_i]) take=1+solve(ind+1,ind,nums,dp);
        return dp[ind][prev_i+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev_i=ind-1;prev_i>=-1;prev_i--)
            {
                int not_take=dp[ind+1][prev_i+1];
                int take=0;
                if(prev_i==-1 || nums[ind]>nums[prev_i]) take=1+dp[ind+1][ind+1];
                dp[ind][prev_i+1]=max(take,not_take);
            }
        }


        return dp[0][0];
    }
};