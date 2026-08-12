class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 1;
        unordered_map<int,int> mp;
        int l=0,r=0;
        int mx=0;
        while(l<n && r<n){
            mp[nums[r]]++;
            if(mp[nums[r]]>k){
                mx=max(mx,r-l);
                while(mp[nums[r]]>k){
                    mp[nums[l]]--;
                    l++;
                }
            }
            else mx=max(mx,r-l+1);
            r++; 
        }

        return mx;
    }
};