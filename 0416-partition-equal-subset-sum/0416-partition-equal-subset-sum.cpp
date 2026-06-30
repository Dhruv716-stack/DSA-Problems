class Solution {
public:

    vector<vector<int>> dp;
    bool solve(int ind, int tar, vector<int>&arr){
        int n=arr.size();

        if(tar==0) return true;
        if(ind>=n) return false;
        if(tar<0) return false;
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        bool t=false,nt=false;
        if(arr[ind]<=tar)t=solve(ind+1,tar-arr[ind],arr);
        nt=solve(ind+1,tar,arr);
        return dp[ind][tar]=(t||nt); 
    }


    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];

        if(sum%2==1) return false;
        int tar=sum/2;
        dp.assign(n,vector<int>(tar+1,-1));
        return solve(0,tar,nums);
    }
};