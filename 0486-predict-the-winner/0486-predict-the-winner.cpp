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
        dp.assign(n+1,vector<ll>(n+1,0));
        ll p=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i>j) continue;
                ll take_i=0,take_j=0;
                if(i+1<n) take_i= 1LL*nums[i]-dp[i+1][j];
                if(j>0) take_j=1LL*nums[j]-dp[i][j-1];
                dp[i][j]=max(take_i,take_j);
            }
        }
        return dp[0][n-1]>=0;
    }
};