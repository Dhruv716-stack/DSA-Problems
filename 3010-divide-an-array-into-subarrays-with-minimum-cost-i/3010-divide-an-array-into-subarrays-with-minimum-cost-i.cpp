class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a=51,b=51;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(a>nums[i])
            {
                b=a;
                a=nums[i];
            }
            else if(b>nums[i])
            {
                b=nums[i];
            }
            if(a==1 && b==1) break;
        }
        return a+b+nums[0];
    }
};