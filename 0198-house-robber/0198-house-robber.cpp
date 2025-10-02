class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++)
        {
            int take=nums[i];
            if(i>1) take+=prev2;
            int not_take=prev1;
            int curri=max(take,not_take);
            prev2=prev1;
            prev1=curri;
        }
        return prev1;
        
    }
};