class Solution {
public:
    long long solve(int i,string &s,long long ans)
    {
        int n=s.size();
        if(i==n) return ans;
        long long x=(s[i]-'0');
        if (ans > (LLONG_MAX - x) / 10) return LLONG_MAX;
        return solve(i+1,s,ans*10+x);
        
    }
    int myAtoi(string s) {
        int n=s.size();
        string s1="";
        if((s[0]>='A' && s[0]<='Z')||(s[0]>='a' && s[0]<='z') || s[0]=='.') return 0;
        int idx=0;
        while(idx<n && s[idx]==' ') idx++;
        bool neg=false;
        if(idx<n && (s[idx]=='+' ||s[idx]=='-'))
        {
            if(s[idx]=='-') neg=true;
            idx++;
        }
        if((s[idx]>='A' &&s[idx]<='Z') || (s[idx]>='a' && s[idx]<='z') || s[idx]=='+' || s[idx]=='-' || s[idx]=='.' || s[idx]==' ') return 0;
        while(idx<n)
        {
            if(s[idx]>='0' && s[idx]<='9') break;
            idx++;
        }
        while(idx<n)
        {
            if(s[idx]=='0' && n!=1) idx++;
            else break;
        }
        for(int i=idx;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9') s1+=s[i];
            else break;
        }
        long long ans=0;
        ans=solve(0,s1,ans);
        if(neg==true) ans=-1*ans;
        if(ans>=INT_MAX) return INT_MAX;
        if(ans<=INT_MIN) return INT_MIN;
        return ans;

    }
};