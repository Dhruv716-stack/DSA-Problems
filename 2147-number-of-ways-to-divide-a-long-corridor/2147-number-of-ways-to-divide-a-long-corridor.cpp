class Solution {
public:
    const int M=1e9 +7;
    int numberOfWays(string c) {
        int n=c.size();
        vector<int> v;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(c[i]=='S')
            {
                cnt++;
                v.push_back(i);
            }
        }
        if(cnt%2!=0 || cnt==0) return 0;
        int prev=v[1];
        long long res=1;
        for(int i=2;i<v.size();i+=2)
        {
            int curr=v[i];
            res=(res*(curr-prev))%M;
            prev=v[i+1];
        }
        return res;
    }
};