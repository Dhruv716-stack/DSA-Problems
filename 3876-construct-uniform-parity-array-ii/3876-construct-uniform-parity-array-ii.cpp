class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int cnt1=0,cnt2=0,mno=INT_MAX;
        for(int i=0;i<n;i++)
            {
                if((nums1[i]&1)==1)
                {
                    cnt1++;
                    mno=min(mno,nums1[i]);
                }
                else cnt2++;
            }
        if(cnt1==0 || cnt2==0) return true;
        for(int i=0;i<n;i++)
            {
                if((nums1[i]&1)==0)
                {
                    if(nums1[i]<=mno) return false;
                }
            }
        return true;
    }
};