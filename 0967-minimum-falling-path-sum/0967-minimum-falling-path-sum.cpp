class Solution {
public:
int solve(vector<vector<int>> &mat, int i, int j, vector<vector<int>>& dp) {
    int n = mat.size();

    // boundary check
    if (j < 0 || j >= n) return INT_MAX;

    // base case
    if (i == n - 1) return mat[i][j];

    // memoization check
    if (dp[i][j] != INT_MAX) return dp[i][j];

    // recursive calls (with overflow safety)
    int down = solve(mat, i + 1, j, dp);
    int downLeft = solve(mat, i + 1, j - 1, dp);
    int downRight = solve(mat, i + 1, j + 1, dp);

    int minNext = min({down, downLeft, downRight});

    if (minNext == INT_MAX)  // all invalid paths
        return dp[i][j] = INT_MAX;

    // safe addition — no overflow
    return dp[i][j] = mat[i][j] + minNext;
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    int ans = INT_MAX;

    for (int j = 0; j < n; j++) {
        ans = min(ans, solve(matrix, 0, j, dp));
    }
    return ans;
}

};