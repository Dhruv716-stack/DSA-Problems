class Solution {
public:
    vector<bool> dp;
    bool solve(vector<int>&arr, int i, vector<int>&vis)
    {
        int n=arr.size();
        if(i+arr[i]<n) if(arr[i+arr[i]]==0) return true;
        if(i-arr[i]>=0) if(arr[i-arr[i]]==0) return true;
        if(vis[i]==1) return false;
        if(dp[i]==true) return dp[i];
        vis[i]=1;
        bool l=false,r=false;
        if(i+arr[i]<n)
        {
            r=solve(arr,i+arr[i],vis);
        }
        if(i-arr[i]>=0) l=solve(arr,i-arr[i],vis);
        return dp[i]=(l||r);

    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        dp.assign(n,false);
        vector<int> vis(n,0);
        return solve(arr,start,vis);
    }
};