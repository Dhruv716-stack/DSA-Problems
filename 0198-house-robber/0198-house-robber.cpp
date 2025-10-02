class Solution {
public:
    int solve(vector<int>&arr,int n,int ind,vector<int>&dp)
    {
        if(ind==0) return arr[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=arr[ind]+solve(arr,n,ind-2,dp);
        int not_pick=solve(arr,n,ind-1,dp);
        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int ans=solve(nums,n,n-1,dp);
        return ans;
    }
};