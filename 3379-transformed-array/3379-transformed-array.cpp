class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++)
        {
            int k=abs(nums[i]);
            k=k%n;
            if(nums[i]>0) res[i]=nums[(i+k+n)%n];
            else if(nums[i]<0) res[i]=nums[(i-k+n)%n];
            else res[i]=nums[i];
        }
        return res;
    }
};