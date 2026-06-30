class Solution {
public:

    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];

        if(sum%2==1) return false;
        int tr=sum/2;
        dp.assign(n+1,vector<int>(tr+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int ind=n-1;ind>=0;ind--){
            for(int tar=0;tar<=tr;tar++){
                bool t=false,nt=false;
                if(nums[ind]<=tar) t=dp[ind+1][tar-nums[ind]];
                nt=dp[ind+1][tar];
                dp[ind][tar]=(t||nt);
            }
        }

        return dp[0][tr];
    }
};