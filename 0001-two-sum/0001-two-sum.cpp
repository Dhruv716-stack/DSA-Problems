class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        int n=nums.size();
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        int sum=target;
        while(i<j)
        {
            if(v[i].first+v[j].first<sum)
            {
                i++;
            }
            else if(v[i].first+v[j].first>sum) j--;
            else if(v[i].first+v[j].first==sum) return {v[i].second,v[j].second};
        }
        return {0,0};
    }
};