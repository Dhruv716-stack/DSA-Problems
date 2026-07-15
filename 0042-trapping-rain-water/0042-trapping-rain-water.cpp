class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1,lm=0,rm=0,ans=0;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(lm>arr[l]) ans+=lm-arr[l];
                else lm=arr[l];
                l++;
            }
            else{
                if(rm>arr[r]) ans+=rm-arr[r];
                else rm=arr[r];
                r--;
            }
        }
        return ans;
    }
};