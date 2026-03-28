class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int N = nums.size();
        int n1 = N / 2;
        int n2 = N - n1;

        unordered_map<int, int> right; // xor -> max size

        // Process right half
        for (int mask = 0; mask < (1 << n2); mask++) {
            int xr = 0, sz = 0;
            for (int i = 0; i < n2; i++) {
                if (mask & (1 << i)) {
                    xr ^= nums[n1 + i];
                    sz++;
                }
            }
            right[xr] = max(right[xr], sz);
        }

        int res = 0;

        // Process left half
        for (int mask = 0; mask < (1 << n1); mask++) {
            int xr = 0, sz = 0;
            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i)) {
                    xr ^= nums[i];
                    sz++;
                }
            }

            int need = target ^ xr;

            if (right.count(need)) {
                res = max(res, sz + right[need]);
            }
        }

        if (res == 0 && target != 0) return -1;

        return N - res;
    }
};