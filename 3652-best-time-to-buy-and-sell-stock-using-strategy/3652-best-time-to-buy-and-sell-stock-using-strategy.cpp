class Solution {
public:    
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        int l=0,r=k-1;
        
        vector<long long> p1(n+1,0),p2(n+1,0);
        p1[0]=0;
        p2[0]=0;
        for(int i=0;i<n;i++)
        {
            p1[i+1]=prices[i]+p1[i];
            p2[i+1]=(prices[i]*1LL*strategy[i])+p2[i];
        }

        long long profit=p2[n];
        //long long temp_pro=p2[n];
        long long ans=LLONG_MIN;

        while(l<n && r<n)
        {
            int mid=l+k/2;
            long long remove=(p2[r+1]-p2[l]); //l+1-1
            long long add=(p1[r+1]-p1[mid]);   // r/2+1-1
            long long temp_pro=profit-remove+add;
            ans=max({temp_pro,ans,profit});
            l++;
            r++;
        }
        return ans;
    }
};