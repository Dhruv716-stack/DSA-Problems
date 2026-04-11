class Solution {
public:
    bool check_diff_array(vector<int>&nums,vector<vector<int>>&queries,int k)
    {
        int n=nums.size();
        vector<int> diff(n,0);
        for(int i=0;i<=k;i++)
        {
            int s=queries[i][0];
            int e=queries[i][1];
            int x=queries[i][2];
            diff[s]+=x;
            if(e+1<n) diff[e+1]-=x;
        }
        if(nums[0] > diff[0]) return false;
        for(int i=1;i<n;i++)
        {
            diff[i]=diff[i]+diff[i-1];
            if(nums[i]>diff[i]) return false;
        }
        return true;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         int n=nums.size();
         int Q=queries.size();
         int l=0,h=Q-1;
         int ans=-1;
         int cnt=0;
         for(int i=0;i<n;i++)
         {
            if(nums[i]==0) cnt++;
         }
         if(cnt==n) return 0;
         while(l<=h)
         {
            int mid=l+(h-l)/2;
            if(check_diff_array(nums,queries,mid)==true)
            {
                ans=mid+1;
                h=mid-1;
            }
            else l=mid+1;
         }
         return ans;
    }
};