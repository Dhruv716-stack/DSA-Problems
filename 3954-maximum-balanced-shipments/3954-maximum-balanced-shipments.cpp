class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int l=0,r=0;
        int cnt=0;
        int n=weight.size();
        int mx=0;
        while(l<n && r<n)
        {
            mx=max(mx,weight[r]);
            if(mx>weight[r])
            {
                l=r+1;
                cnt++;
                mx=0;
            }
            r++;
        }
        return cnt;
    }
};