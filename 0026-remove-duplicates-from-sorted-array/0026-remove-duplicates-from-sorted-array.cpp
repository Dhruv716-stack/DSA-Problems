class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        while(i<n && j<n)
        {
            if(nums[i]!=nums[j])
            {
                if(i+1<n) nums[i+1]=nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};