class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int max_len=0;
        for(int i=0;i<n;i++)
        {
            int even=0,odd=0;
            unordered_map<int,int> mp;
            if(nums[i]%2==0 && mp.find(nums[i])==mp.end())
            {
                even++;
                mp[nums[i]]=1;
            }
            else if(nums[i]%2==1 && mp.find(nums[i])==mp.end())
            {
                odd++;
                mp[nums[i]]=1;
            }
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]%2==1 && mp.find(nums[j])==mp.end())
                {
                    odd++;
                    mp[nums[j]]=1;
                }
                else if(nums[j]%2==0 && mp.find(nums[j])==mp.end())
                {
                    even++;
                    mp[nums[j]]=1;
                }
            if(even==odd)
            {
                int len=j-i+1;
                max_len=max(max_len,len);
            }
            } 
        }
        return max_len;
    }
};