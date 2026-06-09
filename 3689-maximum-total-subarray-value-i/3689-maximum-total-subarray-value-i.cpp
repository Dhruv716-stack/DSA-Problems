class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long maxi=LLONG_MIN;
        long long mini=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,1LL*nums[i]);
            mini=min(mini,1LL*nums[i]);
        }

        return (maxi-mini)*k;
    }
};