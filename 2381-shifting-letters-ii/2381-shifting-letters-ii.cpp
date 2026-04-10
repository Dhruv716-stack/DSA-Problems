class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> diff(n,0);
        for(auto &it:shifts)
        {
            int s=it[0];
            int e=it[1];
            int dir=it[2];
            int x=1;
            if(dir==0) x=-1;
            diff[s]+=x;
            if(e+1<n) diff[e+1]-=x;
        }

        for(int i=1;i<n;i++) diff[i]=diff[i]+diff[i-1];
        for(int i=0;i<n;i++)
        {
            diff[i]=diff[i]%26;
            if(diff[i]<0) diff[i]+=26;
        }

        for(int i=0;i<n;i++)
        {
            s[i]=(((s[i]-'a')+diff[i])%26)+'a';
        }
        return s;
    }
};