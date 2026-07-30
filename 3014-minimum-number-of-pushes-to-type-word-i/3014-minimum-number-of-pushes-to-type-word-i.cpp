class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> mp;
        int n=word.size();
        for(int i=0;i<n;i++){
            mp[word[i]]++;
        }

        vector<pair<char,int>> v(mp.begin(),mp.end());

        sort(v.begin(),v.end(),[](const auto &a, const auto &b){
            return a.second>b.second;
        });

        int ans=0;
        int cnt=0;

        for(auto &it:v){
            cnt++;
            if(cnt<=8) ans+=it.second;
            else if(cnt<=16) ans+=2*(it.second);
            else if(cnt<=24) ans+=3*(it.second);
            else ans+=4*(it.second);
        }

        return ans;
    }
};