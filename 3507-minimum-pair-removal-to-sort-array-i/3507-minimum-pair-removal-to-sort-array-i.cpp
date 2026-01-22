class Solution {
public:
    
    int minimumPairRemoval(vector<int>& nums) {
        
        
        int cnt=0;
        if(is_sorted(nums.begin(),nums.end())==true) return cnt;
        while(nums.size()>0)
        {
        int n=nums.size();
        int mn_sum=INT_MAX,ind=0;
        for(int i=0;i<n-1;i++)
        {
            int p_sum=nums[i]+nums[i+1];
            if(p_sum<mn_sum)
            {
                mn_sum=p_sum;
                ind=i;
            }
        }
        nums[ind]=mn_sum;
        nums.erase(nums.begin()+ind+1);
        cnt++;
        if(is_sorted(nums.begin(),nums.end())==true) return cnt;
        }
        return cnt;
    }
};