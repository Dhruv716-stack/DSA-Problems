class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0,j=2;
        while(i<n && j<n)
        {
            if(v[i].first==v[j].first)
            {
                int ans=abs(v[i].second-v[j].second)+abs(v[i+1].second-v[j].second)+abs(v[i].second-v[i+1].second);
                mn=min(mn,ans);
            }
            i++;
            j++;
        }
        if(mn==INT_MAX) return -1;
        return mn;
    }
};