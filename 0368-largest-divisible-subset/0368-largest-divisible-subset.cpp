class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n,0);
        int last_ind=0;
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if((nums[prev]%nums[i]==0 || nums[i]%nums[prev]==0) && (1+dp[prev]>dp[i]))
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                last_ind=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[last_ind]);
        while(last_ind!=hash[last_ind])
        {
            temp.push_back(nums[hash[last_ind]]);
            last_ind=hash[last_ind];
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};