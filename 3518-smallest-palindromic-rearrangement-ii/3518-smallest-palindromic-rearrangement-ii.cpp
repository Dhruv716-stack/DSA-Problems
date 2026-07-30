class Solution {
public:
    typedef long long ll;

    ll nCr(int n, int r, ll k) {
        r = min(r, n - r);

        ll res = 1;

        for(int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;

            if(res >= k)
                return k;
        }

        return res;
    }

    ll cal_ways(int letters, vector<int>& cnt, ll k) {
        ll ways = 1;

        for(int i = 0; i < 26; i++) {

            if(cnt[i] > 0) {
                ll cur = nCr(letters, cnt[i], k);

                ways = min(k, ways * cur);

                letters -= cnt[i];
            }

            if(ways >= k)
                break;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();

        char mid = s[n / 2];

        vector<int> cnt(26, 0);

        for(int i = 0; i < n; i++) {
            if(n % 2 == 1 && i == n / 2)
                continue;

            cnt[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
            cnt[i] /= 2;

        int half = n / 2;

        
        ll total_ways = cal_ways(half, cnt, k);

        if(total_ways < k)
            return "";

        string hr;

        for(int i = 0; i < half; i++) {

            for(int j = 0; j < 26; j++) {

                if(cnt[j] == 0)
                    continue;

                
                cnt[j]--;

                ll ways = cal_ways(half - i - 1, cnt, k);

                if(k <= ways) {
                    hr.push_back('a' + j);
                    break;
                }

                
                k -= ways;

                
                cnt[j]++;
            }
        }

        string rev_hr = hr;
        reverse(rev_hr.begin(), rev_hr.end());

        if(n % 2 == 1)
            return hr + mid + rev_hr;

        return hr + rev_hr;
    }
};