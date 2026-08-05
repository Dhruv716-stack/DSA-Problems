class Solution {
public:
    vector<int> dp;
    int solve(int ind, vector<int>&nums){
        int n=nums.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take=0,not_take=0;
        not_take=solve(ind+1,nums);
        take=nums[ind]+solve(ind+2,nums);
        return dp[ind]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,-1);
        return solve(0,nums);
    }
};