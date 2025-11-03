class Solution {
public:
    const long long M=1e17;
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long ans=1;
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(abs(nums[i]));
        }
        sort(arr.begin(),arr.end());
        ans=1LL*arr[n-1]*1LL*arr[n-2]*1e5;
        return ans;
    }
};