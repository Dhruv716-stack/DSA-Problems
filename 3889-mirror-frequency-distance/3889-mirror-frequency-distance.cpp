class Solution {
public:
    int mirrorFrequency(string s) {
        string s1="abcdefghijklmnopqrstuvwxyz";
        string s2=s1;
        reverse(s1.begin(),s1.end());
        string s3="0123456789";
        string s4=s3;
        reverse(s3.begin(),s3.end());
        unordered_map<char,char> mp1;
        unordered_set<char> st;
        for(int i=0;i<s1.size();i++) mp1[s2[i]]=s1[i];
        for(int i=0;i<s3.size();i++) mp1[s4[i]]=s3[i];
        unordered_map<char,int> mp2;

        for(int i=0;i<s.size();i++) mp2[s[i]]++;
        int ans=0;
        for(auto &it:mp2)
        {
            char c=it.first;
            int freqc=it.second;
            if(st.count(c)) continue;
            char m=mp1[c];
            if(mp2.find(m)==mp2.end()) ans+=freqc;
            else ans+=abs(freqc-mp2[m]);
            st.insert(c);
            st.insert(m);
        }
        return ans;
    }
};