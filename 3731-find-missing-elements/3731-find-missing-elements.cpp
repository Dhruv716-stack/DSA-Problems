class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX,mx=INT_MIN;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
            mp[nums[i]]++;
        }

        vector<int> ans;
        for(int i=mn;i<=mx;i++){
            if(mp.find(i)==mp.end()) ans.push_back(i);
        }
        return ans;
    }
};