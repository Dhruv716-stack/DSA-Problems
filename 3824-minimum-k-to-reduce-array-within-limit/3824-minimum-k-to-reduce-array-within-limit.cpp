class Solution {
public:
    int operations(vector<int>&nums,int mid)
    {
        int n=nums.size();
        int op=0;
        for(int i=0;i<n;i++)
        {
            op+=int(ceil((double(nums[i])/double(mid))));
        }
        return op;
    }
    int minimumK(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        long long h=ceil(sqrt(sum));
        long long l=1;
        long long ans=0;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            long long op=1LL*operations(nums,mid);
            if(op<=(mid*mid))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;

    }
};