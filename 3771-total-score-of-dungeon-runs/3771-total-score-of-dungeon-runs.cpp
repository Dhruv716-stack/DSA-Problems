class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n=damage.size();
        vector<int> p(n+1);
        long long ans=0;
        //p[1]=damage[0];
        for(int i=1;i<=n;i++)
        {
            p[i]=p[i-1]+damage[i-1];
        }
        for(int j=1;j<=n;j++)
        {
            int target=p[j]+requirement[j-1]-hp;
            auto lb=lower_bound(p.begin(),p.begin()+j,target);
            int ind=lb-p.begin();
            if(ind<=j-1) ans+=(j-ind);
        }
        return ans;
    }
};