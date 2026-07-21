class Solution {
public:
    typedef long long ll;
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            ll mn=1LL*nums[i],mx=1LL*nums[i];
            for(int j=i;j<n;j++){
                if(1LL*nums[j]<mn) mn=nums[j];
                if(1LL*nums[j]>mx) mx=nums[j];
                ll diff=mx-mn;
                ans+=diff;
            }
        }
        return ans;
    }
};