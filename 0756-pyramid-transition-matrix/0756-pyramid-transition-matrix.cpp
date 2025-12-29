class Solution {
public:
    unordered_map<string,bool> t;
    bool solve(string &curr, int idx, unordered_map<string,vector<char>>&mp,string above,unordered_map<string,bool>&t)
    {
        if(curr.length()==1) return true;
        string key=curr+"_"+to_string(idx)+"_"+above;
        if(t.count(key)) return t[key];
        if(idx==curr.length()-1)
        {
            return t[key]=solve(above,0,mp,"",t);
        }
        string pair=curr.substr(idx,2);
        if(mp.find(pair)==mp.end()) return t[key]= false;
        for(auto &it:mp[pair])
        {
            above.push_back(it);
            if(solve(curr,idx+1,mp,above,t)==true) return t[key]= true;
            above.pop_back();
        }
        return t[key]=false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n=allowed.size();
        unordered_map<string,vector<char>> mp;
        for(int i=0;i<n;i++)
        {
            string s=allowed[i];
            char ch=s[2];
            mp[s.substr(0,2)].push_back(ch);
        }
        return solve(bottom,0,mp,"",t);
    }
};