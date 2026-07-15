class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pmax(n,0),smax(n,0);
        pmax[0]=height[0];
        smax[n-1]=height[n-1];
        for(int i=1;i<n;i++) pmax[i]=max(pmax[i-1],height[i]);
        for(int i=n-2;i>=0;i--) smax[i]=max(smax[i+1],height[i]);

        int ans=0;
        for(int i=0;i<n;i++){
            int lm=pmax[i],rm=smax[i];
            if(height[i]<lm && height[i]<rm){
                int water=min(lm,rm)-height[i];
                ans+=water;
            }
        }
        return ans;
    }
};