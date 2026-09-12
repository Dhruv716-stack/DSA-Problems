class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);

        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];

        for(int i=1;i<n;i++){
            leftmax[i]=max(height[i],leftmax[i-1]);
            rightmax[n-1-i]=max(height[n-1-i],rightmax[n-i]);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int mn=min(leftmax[i],rightmax[i]);
            if(mn==0) continue;
            else{
                ans+=(mn-height[i]);
            }
        }

        return ans;
    }
};