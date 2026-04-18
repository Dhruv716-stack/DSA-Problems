class Solution {
public:
    int Reverse(int n)
    {
        int rev=0;
        while(n>0)
        {
            int r=n%10;
            rev=rev*10+r;
            n=n/10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[Reverse(nums[i])]=i;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};