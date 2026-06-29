class Solution {
public:
    vector<int> lps_code(string &s)
    {
        int n=s.size();
        vector<int> lps(n,0);
        int len=0;
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0) len=lps[len-1];
                else lps[i]=0;
                i++;
            }
        }
        return lps;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.size();
        int ans=0;
        for(auto &w:patterns){
            int m=w.size();
            vector<int> lps=lps_code(w);

            int i=0;
            int j=0;
            while(i<n && j<m){
                if(w[j]==word[i]){
                    i++;
                    j++;
                }

                else if(w[j]!=word[i]){
                    if(j!=0) j=lps[j-1];
                    else i++;
                }
            }

            if(j==m) ans++;
        }
        return ans;
    }
};