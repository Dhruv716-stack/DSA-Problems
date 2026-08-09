class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int person, int i, int m, vector<int>&nums){
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[person][i][m]!=-1) return dp[person][i][m];
        int res;
        res=person==1?-1:INT_MAX;
        int stones=0;
        for(int x=1;x<=min(n-i,2*m);x++){
            stones+=nums[i+x-1];
            if(person==1){
                res=max(res,stones+solve(0,i+x,max(m,x),nums));
            }
            else{
                res=min(res,solve(1,i+x,max(m,x),nums));
            }
        }
        return dp[person][i][m]=res;
    } 
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp.assign(2,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return solve(1,0,1,piles);
    }
};