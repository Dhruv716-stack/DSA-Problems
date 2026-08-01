class Solution {
public:
    typedef long long ll;
    vector<vector<ll>> dp;
    ll solve(int i, int j,vector<int>&nums){
        int n=nums.size();
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        ll take_i=1LL*nums[i]-solve(i+1,j,nums);
        ll take_j=1LL*nums[j]-solve(i,j-1,nums);
        return dp[i][j]=max(take_i,take_j);
    } 
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        ll sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        dp.assign(n,vector<ll>(n,-1));
        ll p=solve(0,n-1,nums);
        return p>=0;
    }
};