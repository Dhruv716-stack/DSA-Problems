class Solution {
public:
    typedef long long ll;
    vector<vector<int>> dp;
    bool solve(int n, int person){
        if(n==0){
            if(person==0){
                return true;
            }
            else return false;
        }

        if(dp[n][person]!=-1) return dp[n][person];
        bool res= (person==0);
        for(ll x=1;x*x<=n;x++){
            ll square=x*x;
            if(square>n) break;
            else{
                if(person==1){
                    res= res || solve(n-square,0);
                }
                else res= res && solve(n-square,1);
            }
        }

        return dp[n][person]=res;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1,vector<int>(2,-1));
        return solve(n,1);
    }
};