class Solution {
private:
void greaterswap(vector<int>&nums1, int ind1, vector<int>&nums2,int ind2)
{
    if(nums1[ind1]>nums2[ind2]) swap(nums1[ind1],nums2[ind2]);
    return;
}
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap=(n+m)/2+ (n+m)%2;
        while(gap>0)
        {
            int l=0;
            int r=l+gap;
            while(r<n+m)
            {
                //arr1 and arr2
                if(l<m && r>=m)
                {
                    greaterswap(nums1,l,nums2,r-m);
                }

                //arr2 and arr2
                else if(l>=m && r>=m)
                {
                    greaterswap(nums2,l-m,nums2,r-m);
                }

                //arr1 and arr2
                else{
                    greaterswap(nums1,l,nums1,r);
                }
                l++;
                r++;
            }
            if(gap==1) break;
            gap=gap/2 +gap%2;
        }

        for(int i=m;i<m+n;i++)
        {
            nums1[i]=nums2[i-m];
        }
        return;
    }
};