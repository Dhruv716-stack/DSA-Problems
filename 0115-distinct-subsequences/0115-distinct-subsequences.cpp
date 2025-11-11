using int128 = __int128;
const int M=1e9+7;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int128>> dp(n+1,vector<int128>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int j=1;j<=m;j++) dp[0][j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%M;
                else dp[i][j]=(dp[i-1][j])%M;
            }
        }
        return (long long)(dp[n][m])%M;
    }
};