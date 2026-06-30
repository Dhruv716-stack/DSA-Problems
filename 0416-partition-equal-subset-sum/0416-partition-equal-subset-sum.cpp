class Solution {
public:

    //vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];

        if(sum%2==1) return false;
        int tr=sum/2;
        vector<int> temp(tr+1,0),curr(tr+1,0);
        for(int i=0;i<=n;i++){
            temp[0]=1;
        }

        for(int ind=n-1;ind>=0;ind--){
            for(int tar=0;tar<=tr;tar++){
                bool t=false,nt=false;
                if(nums[ind]<=tar) t=temp[tar-nums[ind]];
                nt=temp[tar];
                curr[tar]=(t||nt);
            }
            temp=curr;
        }

        return curr[tr];
    }
};