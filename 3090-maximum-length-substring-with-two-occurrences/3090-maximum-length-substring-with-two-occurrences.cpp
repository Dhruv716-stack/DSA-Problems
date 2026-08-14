class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int mx=0;
        while(i<n && j<n){
            mp[s[j]]++;
            if(mp[s[j]]>2){
                mx=max(mx,j-i);
                while(mp[s[j]]>2){
                    mp[s[i]]--;
                    i++;
                }
            }
            else mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};