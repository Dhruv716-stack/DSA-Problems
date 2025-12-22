class Solution {
public:
    int solve(int ind, int cnt, int mod,
              vector<int>& nums,
              vector<vector<vector<int>>>& dp)
    {
        int n = nums.size();

        // must pick exactly cnt numbers
        if (cnt == 0) {
            return (mod == 0 ? 0 : INT_MIN);
        }

        // array finished but still need picks → invalid
        if (ind == n) return INT_MIN;

        if (dp[ind][cnt][mod] != -1)
            return dp[ind][cnt][mod];

        int not_take = solve(ind + 1, cnt, mod, nums, dp);

        int take = solve(ind + 1, cnt - 1,
                         (mod + nums[ind]) % 3,
                         nums, dp);

        if (take != INT_MIN)
            take += nums[ind];

        return dp[ind][cnt][mod] = max(take, not_take);
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(4, vector<int>(3, -1))
        );

        int ans = solve(0, 3, 0, nums, dp);
        return (ans < 0 ? 0 : ans);
    }
};