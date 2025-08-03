class Solution {
public:
    bool isTrionic(vector<int>& nums) {
                int cntp=0;
        for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i+1]>nums[i]) cntp++;
                else break;
            }
        if(cntp==0) return false;
        int cntq=cntp;
        for(int i=cntp;i<nums.size()-1;i++)
            {
                if(nums[i+1]<nums[i]) cntq++;
                else break;
            }
        if(cntq==cntp) return false;
        int cntz=cntq;
        for(int i=cntq;i<nums.size()-1;i++)
            {
                if(nums[i+1]>nums[i]) cntz++;
                else break;
            }
        if(cntz!=nums.size()-1 || cntz==cntq||cntz==cntp) return false;
        return true;
    }
    
};