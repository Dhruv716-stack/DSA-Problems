class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int max_len=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        while(i<n &&j<n)
        {
            while(i<n && j<n && 1LL*nums[i]*k>=1LL*nums[j])
            {
                int len=j-i+1;
                max_len=max(max_len,len);
                j++;
            }
            i++;
        }
        return n-max_len;
    }
};