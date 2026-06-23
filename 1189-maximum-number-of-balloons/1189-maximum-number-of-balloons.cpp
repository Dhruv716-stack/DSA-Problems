class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        unordered_map<char,int> mp;
        string s="balloon";
        for(auto &l:s)
        {
            mp[l]=0;
        }

        for(int i=0;i<n;i++)
        {
            if(text[i]=='b' || text[i]=='a' ||text[i]=='l' || text[i]=='o' || text[i]=='n') mp[text[i]]++;
        }

        int mn=INT_MAX;
        for(auto &it:mp)
        {
            int num=it.second;
            if(it.first=='l' || it.first=='o') num=num/2;
            mn=min(mn,num);
        }
        if(mn==INT_MAX) return 0;
        return mn;
    }
};