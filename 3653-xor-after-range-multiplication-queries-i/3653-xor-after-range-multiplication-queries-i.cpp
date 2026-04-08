class Solution {
public:
    const int M=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<long long> nums2(n,0);
        for(int i=0;i<n;i++)
        {
            nums2[i]=1LL*nums[i];
        }
        for(int i=0;i<m;i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];
            int idx=l;
            while(idx<=r)
            {
                nums2[idx]=(1LL*nums2[idx]*v)%M;
                idx+=k;
            }
        }

        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=(ans^nums2[i]);
        }
        return ans;
    }
};