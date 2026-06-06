class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(i<n && j<n)
        {
            if((nums[i]^nums[j])==0) return nums[i];
            i++;
            j++;
        }
        return 0;
    }
};