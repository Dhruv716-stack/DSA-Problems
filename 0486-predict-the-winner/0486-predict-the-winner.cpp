class Solution {
public:
    typedef long long ll;
    vector<vector<ll>> dp;
    ll solve(int i, int j,vector<int>&nums){
        int n=nums.size();
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        ll take_i=1LL*nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        ll take_j=1LL*nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));
        return dp[i][j]=max(take_i,take_j);
    } 
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        ll sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        dp.assign(n,vector<ll>(n,-1));
        ll p1=solve(0,n-1,nums);
        ll p2=sum-p1;
        return p1>=p2;
    }
};