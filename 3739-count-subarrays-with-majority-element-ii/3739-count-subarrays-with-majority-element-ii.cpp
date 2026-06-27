class Solution {
public:
    typedef long long ll;
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        ll cumsum=0;
        ll vlp=0;
        ll ans=0;
        unordered_map<ll,ll> mp;
        mp[cumsum]++;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                vlp+=mp[cumsum];
                cumsum++;
            }
            else{
                cumsum--;
                vlp-=mp[cumsum];
            }

            ans+=vlp;
            mp[cumsum]++;
        }

        return ans;

    }
};