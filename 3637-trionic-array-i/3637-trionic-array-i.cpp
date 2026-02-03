class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n-1 && nums[i]<nums[i+1]) i++;
        if(i==0) return false;

        int ind=i;

        while(i<=n-2)
        {
            if(nums[i+1]<nums[i]) i++;
            else break;
        } 
        if(i==ind) return false;

        int ind2=i;
        while(i<=n-2)
        {
            if(nums[i]<nums[i+1]) i++;
            else return false;
        }
        if(ind2==i) return false;


        return true;
    }
};