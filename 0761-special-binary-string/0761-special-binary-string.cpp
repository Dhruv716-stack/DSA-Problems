class Solution {
public: 
    string solve(string s)
    {
        int sum=0;
        vector<string> special;
        int start=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') sum++;
            if(s[i]=='0') sum--;
            if(sum==0)
            {
                string inner=s.substr(start+1,i-start-1);
                special.push_back("1" + solve(inner) +"0");
                start=i+1;
            }
        }

        sort(special.begin(),special.end(),greater<string>());
        string res="";
        for(auto s:special)
        {
            res+=s;
        }
        return res;
    }
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};