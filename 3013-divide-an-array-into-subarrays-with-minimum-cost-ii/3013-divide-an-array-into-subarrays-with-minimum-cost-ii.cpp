class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> P;

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n =nums.size();
        set<P> sm;
        set<P> sr;
        int i=1;
        ll sum=0;
        while(i-dist<1)
        {
            sum+=nums[i];
            sm.insert({nums[i],i});
            P remove=*sm.rbegin();
            if(sm.size()>k-1)
            {
                sum-=remove.first;
                sr.insert(remove);
                sm.erase(remove);
            }
            i++;
        }
        ll res=LONG_MAX;
        while(i<n)
        {
            sum+=nums[i];
            sm.insert({nums[i],i});
            P remov=*sm.rbegin();
            if(sm.size()>k-1)
            {
                sr.insert(remov);
                sum-=remov.first;
                sm.erase(remov);
            }

            res = min(res, sum);
            
            //shifting window
            P r={nums[i-dist],i-dist};
            if(sm.count(r))
            {
                sum-=r.first;
                sm.erase(r);

                if(!sr.empty())
                {
                    P temp=*sr.begin();
                    sm.insert(temp);
                    sum+=temp.first;
                    sr.erase(temp);
                }
            }
            else sr.erase(r);
            i++;
        }
        return res+1LL*nums[0];
    }
};