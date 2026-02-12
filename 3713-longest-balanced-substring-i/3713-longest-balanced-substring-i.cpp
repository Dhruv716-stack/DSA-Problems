class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int max_len=1;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> mp;
            mp[s[i]]++;
            for(int j=i+1;j<n;j++)
            {
                mp[s[j]]++;
                int val=mp[s[j]];
                int cnt=0;
                for(auto &it:mp)
                {
                    if(it.second!=val) break;
                    else cnt++;
                }
                if(cnt==mp.size())
                {
                    int len=j-i+1;
                    max_len=max(max_len,len);
                }
            }
        }
        return max_len;
    }
};