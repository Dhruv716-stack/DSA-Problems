class Solution {
public:
    bool solve(vector<int>&nums,int ind,int sum,vector<vector<int>>&dp)
    {
        if(sum==0) return true;
        if(ind==0) return (nums[0]==sum);
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool not_take=solve(nums,ind-1,sum,dp);
        bool take=false;
        if(nums[ind]<=sum) take=solve(nums,ind-1,sum-nums[ind],dp);
        return dp[ind][sum]=(take||not_take);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<bool> prev(target+1,0),curr(target+1,0);
        prev[0]=true;
        curr[0]=true;
        //if (nums[0] <= target) dp[0][nums[0]] = true;
        for(int ind=1;ind<n;ind++)
            {
                for(int sum=1;sum<=target;sum++)
                    {
                        bool not_take=prev[sum];
                        bool take =false;
                        if(nums[ind]<=sum) take=prev[sum-nums[ind]];
                        curr[sum]=(take||not_take);
                    }
                prev=curr;
            }

        return prev[target];
    }
};