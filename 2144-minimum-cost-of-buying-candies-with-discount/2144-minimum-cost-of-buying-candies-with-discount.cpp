class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=cost[i];
        }
        if(n<=2) return sum;
        for(int i=2;i<n;i+=3)
        {
            sum-=cost[i];
        }
        return sum;
    }
};