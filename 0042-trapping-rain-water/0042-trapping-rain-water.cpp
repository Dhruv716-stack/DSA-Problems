class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lm=0,rm=0,l=0,r=n-1,ans=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(lm>height[l]) ans+=(lm-height[l]);
                else lm=height[l];
                l++;
            }
            else{
                if(rm>height[r]) ans+=(rm-height[r]);
                else rm=height[r];
                r--;
            }
        }

        return ans;
    }
};