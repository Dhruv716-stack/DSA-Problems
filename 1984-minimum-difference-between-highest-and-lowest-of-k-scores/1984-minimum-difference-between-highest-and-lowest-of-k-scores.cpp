class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MAX;
        int i=0;
        int j=k-1;
        sort(nums.begin(),nums.end());
        while(i<n && j<n)
        {
            int mx=nums[j];
            int mn=nums[i];
            mini=min(mini,mx-mn);
            i++;
            j++;
        }
        return mini;
    }
};