class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> nums1=nums;
        k=k%n;
        for(int i=0;i<n;i++)
        {
            nums[i]=nums1[(i-k+n)%n];
        }
        return;
    }
};