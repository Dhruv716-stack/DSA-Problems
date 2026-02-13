class Solution {
public:
    int case1(string s)
    {
        int n=s.size();
        int cnt=1;
        int ml=0;
        for(int i=1;i<n;i++)
        {
            if(s[i-1]==s[i])
            {
                cnt++;
            }
            else
            {
                ml=max(ml,cnt);
                cnt=1;
            }
        }
        ml=max(ml,cnt);
        return ml;
    }
    int case2(string s, char ch1, char ch2)
    {
        int n=s.size();
        int cnt1=0,cnt2=0;
        unordered_map<int,int> mp;
        //mp[0]=-1;
        int ml=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=ch1 && s[i]!=ch2)
            {
                mp.clear();
                cnt1=0;
                cnt2=0;
            }
            if(s[i]==ch1) cnt1++;
            if(s[i]==ch2) cnt2++;
            int diff=cnt1-cnt2;
            if(diff==0)
            {
                ml=max(ml,cnt1+cnt2);
            }
            else if(mp.find(diff)!=mp.end())
            {
                ml=max(ml,i-mp[diff]);
            }
            else mp[diff]=i;
        }
        return ml;
    }
    int case3(string s)
    {
        int n=s.size();
        map<pair<int,int>,int> mp;
        //mp[{0,0}]=-1;
        int ml=0;
        int cnta=0,cntb=0,cntc=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a') cnta++;
            if(s[i]=='b') cntb++;
            if(s[i]=='c') cntc++;
            int diffab=cnta-cntb;
            int diffac=cnta-cntc;
            if(cnta==cntb && cnta==cntc)
            {
                ml=max(ml,cnta+cntb+cntc);
            }
            else if(mp.find({diffab,diffac})!=mp.end())
            {
                ml=max(ml,i-mp[{diffab,diffac}]);
            }
            else
            {
                mp[{diffab,diffac}]=i;
            }
        }
        return ml;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        ans=max(ans,case1(s));
        int c1=case2(s,'a','b');
        int c2=case2(s,'b','c');
        int c3=case2(s,'a','c');
        ans=max({ans,c1,c2,c3});
        ans=max(ans,case3(s));
        return ans;
    }
};