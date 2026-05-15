class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]>=nums[l])
            {
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            else if(nums[mid]<=nums[h])
            {
                ans=min(ans,nums[mid]);
                h=mid-1;
            }
        }
        if(n==1) return nums[0];
        return ans;
    }
};