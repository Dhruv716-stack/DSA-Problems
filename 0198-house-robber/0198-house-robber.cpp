class Solution {
public:
    int solve(int i, vector<int>&nums,vector<int>&dp)
    {
        if(i==0) return nums[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int not_take=solve(i-1,nums,dp);
        int take=0;
        if(i>=0) take=nums[i]+solve(i-2,nums,dp);
        return dp[i]=max(not_take,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<long long> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            long long not_take=dp[i-1];
            long long take=1LL*nums[i];
            if(i>1) take+=dp[i-2];
            dp[i]=max(take,not_take);
        }
        return dp[n-1];
    }
};