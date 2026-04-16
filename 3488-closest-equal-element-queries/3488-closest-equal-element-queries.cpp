class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        vector<int>ans;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        for(auto q:queries)
        {
            int ele=nums[q];
            vector<int>&v=mp[ele];
            int sz=v.size();
            if(sz==1)
            {
                ans.push_back(-1);
                continue;
            }

            int pos=lower_bound(v.begin(),v.end(),q)-v.begin();
            int res=INT_MAX;
            //Right neighbour
            int right=v[(pos+1)%sz];
            int d=abs(q-right);
            int cd=abs(n-d);
            res=min({res,d,cd});

            //Left neighbour
            int left=v[(pos-1+sz)%sz];
            d=abs(q-left);
            cd=abs(n-d);
            res=min({res,cd,d});

            res=(res==INT_MAX)?-1:res;
            ans.push_back(res);
        }
        return ans;
    }
};