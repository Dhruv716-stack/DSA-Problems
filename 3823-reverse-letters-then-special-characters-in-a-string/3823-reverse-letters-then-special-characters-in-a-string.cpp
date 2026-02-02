class Solution {
public:
    string reverseByType(string s) {
        int n=s.size();
        vector<int> v1,v2;
        string s1="",s2="";
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z') 
            {s1+=s[i];
            v1.push_back(i);}
            else
            {
                s2+=s[i];
                v2.push_back(i);
            }
        }
        int n1=s1.size();
        int n2=s2.size();
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        for(int i=0;i<n1;i++) s[v1[i]]=s1[i];
        for(int i=0;i<n2;i++) s[v2[i]]=s2[i];
        return s;
    }
};