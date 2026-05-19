class Solution {
public:
    int binary(vector<int>&nums,int target)
    {
        int n=nums.size();
        int l=0,h=n-1;
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
            {
                ans=nums[mid];
                h=mid-1;
            }
            else if(nums[mid]>target) h=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int target=nums1[i];
            ans=min(binary(nums2,target),ans);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};