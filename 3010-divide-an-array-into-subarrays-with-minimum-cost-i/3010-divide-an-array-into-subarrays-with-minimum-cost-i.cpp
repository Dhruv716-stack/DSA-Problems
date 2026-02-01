class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a=INT_MAX,b=INT_MAX;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<a)
            {
                b=a;
                a=nums[i];
            }
            else if(nums[i]<b)
            {
                b=nums[i];
            }
            if(a==1 && b==1) break;
        }
        return nums[0]+a+b;
    }
};