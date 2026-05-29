class Solution {
public:
    int digit_sum(int n)
    {
        int ds=0;
        while(n>0)
        {
            int r=n%10;
            ds+=r;
            n=n/10;
        }
        return ds;
    }
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            nums[i]=digit_sum(nums[i]);
            mn=min(mn,nums[i]);
        }
        return mn;
    }
};