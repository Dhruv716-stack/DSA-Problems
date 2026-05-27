class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        while(i<n && j<n)
        {
            long long sum=1LL*v[i].first+1LL*v[j].first;
            if(sum==1LL*target) return {v[i].second,v[j].second};
            else if(sum>1LL*target)
            {
                j--;
            }
            else 
            {
                i++;
            }
        }

        return {-1,-1};

    }
};